<?php
/**
 * @file
 * swaylocks_base.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function swaylocks_base_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_user_default_permissions_alter().
 */
function swaylocks_base_user_default_permissions_alter(&$data) {
  if (isset($data['post comments'])) {
    $data['post comments']['roles']['moderator'] = 'moderator'; /* WAS: '' */
    $data['post comments']['roles']['trusted'] = 'trusted'; /* WAS: '' */
    unset($data['post comments']['roles']['authenticated user']);
  }
  if (isset($data['skip comment approval'])) {
    $data['skip comment approval']['roles']['moderator'] = 'moderator'; /* WAS: '' */
    $data['skip comment approval']['roles']['trusted'] = 'trusted'; /* WAS: '' */
    unset($data['skip comment approval']['roles']['authenticated user']);
  }
}

/**
 * Implements hook_image_default_styles().
 */
function swaylocks_base_image_default_styles() {
  $styles = array();

  // Exported image style: max_image_width.
  $styles['max_image_width'] = array(
    'label' => 'max_image_width',
    'effects' => array(
      4 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1240,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
