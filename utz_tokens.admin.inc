<?php

/**
 * @file
 * Administration pages for User Time Zone Tokens module.
 */

/**
 * Administration form.
 */
function utz_tokens_admin_form($form, &$form_state) {
  $config = config('utz_tokens.settings');
  $form['#config'] = 'utz_tokens.settings';

  $enabled_modules = $disabled_modules = array();
  if (module_exists('timezone_detect')) {
    $enabled_modules[] = 'Time Zone Detect';
    $msgs[] = t('Time Zone Detect module is enabled.');
  }
  else {
    $disabled_modules[] = 'Time Zone Detect';
    $msgs[] = t('Time Zone Detect module is not enabled.');
  }
  if (module_exists('luxon')) {
    $enabled_modules[] = 'Luxon';
    $msgs[] = t('Luxon module is enabled.');
  }
  else {
    $disabled_modules[] = 'Luxon';
    $msgs[] = t('Luxon module is not enabled.');
  }
  $form[] = array(
    '#markup' => implode(' ', $msgs),
    '#prefix' => '<p>',
    '#suffix' => '</p>',
  );

  $form['detect_anonymous'] = array(
    '#type' => 'checkbox',
    '#title' => t("Detect user timezone for anonymous users"),
    '#default_value' => $config->get('detect_anonymous'),
    '#disabled' => count($enabled_modules) != 2,
  );

  return system_settings_form($form);
}
