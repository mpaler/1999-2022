<?php
/**
 * @file
 * swaylocks_misc.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function swaylocks_misc_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-adplugg_swaylocks_archive_footer'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'machine_name' => 'adplugg_swaylocks_archive_footer',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'forum_plus' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'forum_plus',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['block-adplugg_swaylocks_archive_header'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'machine_name' => 'adplugg_swaylocks_archive_header',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'forum_plus' => array(
        'region' => 'subheader',
        'status' => 1,
        'theme' => 'forum_plus',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['block-adplugg_swaylocks_sidebar_1'] = array(
    'cache' => -1,
    'css_class' => 'row justify-content-center mr-0 ml-0',
    'custom' => 0,
    'machine_name' => 'adplugg_swaylocks_sidebar_1',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'forum_plus' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'forum_plus',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['block-adplugg_swaylocks_sidebar_2'] = array(
    'cache' => -1,
    'css_class' => ' row justify-content-center mr-0 ml-0',
    'custom' => 0,
    'machine_name' => 'adplugg_swaylocks_sidebar_2',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'forum_plus' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'forum_plus',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
