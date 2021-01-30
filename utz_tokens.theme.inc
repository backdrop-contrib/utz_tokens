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
  $timestr = $variables['timestr'];
  $format = $variables['format'];
  try {
    $datetime = new DateTime($timestr); // could fail
    $datetime->setTimeZone(new DateTimeZone(backdrop_get_user_timezone()));
    $format = filter_xss($format);
    $detect_anonymous = config_get('utz_tokens.settings', 'detect_anonymous');
    if ($detect_anonymous) {
      return '<span class="utz-datetime" data-timestamp="' . $datetime->getTimestamp() . '" data-format="' . $format . '" data-anonymous="' . user_is_anonymous() . '">' . $datetime->format($format) . '</span>';
    }
    else {
      return '<span class="utz-datetime">' . $datetime->format($format) . '</span>';
    }
  }
  catch (Exception $e) {
    return t('utz_datetime error: unable to parse time %timestr.', array('%timestr' => $timestr));
  }
}

/** @} End of addtogroup themeable */
