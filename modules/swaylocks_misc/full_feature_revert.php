<?php

/**
 * Completely reverts a feature based on the settings in its .info file.
 * 
 * @param string $feature_module
 *   Name of feature/module to revert.
 */
function full_feature_revert($feature_module) {
  $info = drupal_parse_info_file(drupal_get_path('module', $feature_module) . '/' . $feature_module . '.info');
  $revert = array(
    $feature_module => array_keys($info['features']),
  );
  watchdog('full_feature_revert', 'Reverting feature @feature on behalf of @function', array('@feature' => $feature_module, '@function' => _calling_function()));
  features_revert($revert);
}

/**
 * Get the name of the function that called your function.
 * 
 * @return string
 *   Name of function.
 */
function _calling_function() {
 $trace =  debug_backtrace();
 return $trace[2]['function'];
}
 