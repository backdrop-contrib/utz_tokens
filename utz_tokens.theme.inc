<?php
/**
 * @file
 * Theme and preprocess functions for output by Date module.
 */

/**
 * @addtogroup themeable
 * @{
 */

/**
 * Returns HTML for a utz_datetime element.
 */
function theme_utz_datetime($variables) {
  $datetime = $variables['datetime'];
  $format = $variables['format'];
  try {
    $datetime_obj = new DateTime($datetime); // could fail
    $datetime_obj->setTimeZone(new DateTimeZone(backdrop_get_user_timezone()));
    $format = filter_xss($format);
    $detect_anonymous = config_get('utz_tokens.settings', 'detect_anonymous');
    if ($detect_anonymous) {
      return '<span class="utz-datetime" data-timestamp="' . $datetime_obj->getTimestamp() . '" data-format="' . $format . '" data-anonymous="' . user_is_anonymous() . '">' . $datetime_obj->format($format) . '</span>';
    }
    else {
      return '<span class="utz-datetime">' . $datetime_obj->format($format) . '</span>';
    }
  }
  catch (Exception $e) {
    return t('utz_datetime error: unable to parse time %datetime.', array('%datetime' => $datetime));
  }
}

/** @} End of addtogroup themeable */
