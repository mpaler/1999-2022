<?php
/**
 * @file
 * swaylocks_misc.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function swaylocks_misc_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'my_activity';
  $quicktabs->ajax = 1;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Quicktabs: My Activity Main Tab';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'swaylocks_activity_streams_user_specific_activity_',
      'display' => 'default',
      'args' => '%1',
      'title' => 'My Recent Activity',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'swaylocks_activity_streams_activity_site_wide_',
      'display' => 'panel_pane_4',
      'args' => '',
      'title' => 'Activity I\'m Following',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'Arrows';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Activity I\'m Following');
  t('My Recent Activity');
  t('Quicktabs: My Activity Main Tab');

  $export['my_activity'] = $quicktabs;

  return $export;
}
