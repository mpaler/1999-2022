<?php
/**
 * @file
 * swaylocks_misc.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function swaylocks_misc_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Adplugg - swaylocks_archive_footer';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'adplugg_swaylocks_archive_footer';
  $fe_block_boxes->body = '<div class="adplugg-tag" data-adplugg-zone="swaylocks_archive_footer"></div>';

  $export['adplugg_swaylocks_archive_footer'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Adplugg - swaylocks_archive_header';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'adplugg_swaylocks_archive_header';
  $fe_block_boxes->body = '<div class="adplugg-tag" data-adplugg-zone="swaylocks_archive_header"></div>';

  $export['adplugg_swaylocks_archive_header'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Adplugg - swaylocks_archive_sidebar_1';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'adplugg_swaylocks_sidebar_1';
  $fe_block_boxes->body = '<div class="adplugg-tag" data-adplugg-zone="swaylocks_archive_sidebar_1"></div>';

  $export['adplugg_swaylocks_sidebar_1'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Adplugg - swaylocks_archive_sidebar_2';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'adplugg_swaylocks_sidebar_2';
  $fe_block_boxes->body = '<div class="adplugg-tag" data-adplugg-zone="swaylocks_archive_sidebar_2"></div>';

  $export['adplugg_swaylocks_sidebar_2'] = $fe_block_boxes;

  return $export;
}
