<?php
/**
 * @file
 * swaylocks_marketing.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function swaylocks_marketing_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-footer_content'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'machine_name' => 'footer_content',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'forum_plus' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'forum_plus',
        'weight' => -29,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['simplenews-0'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 0,
    'module' => 'simplenews',
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

  $export['simplenews-1010373'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 1010373,
    'module' => 'simplenews',
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
