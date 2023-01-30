<?php
/**
 * @file
 * swaylocks_misc.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function swaylocks_misc_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_board-archive:archive.
  $menu_links['main-menu_board-archive:archive'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'archive',
    'router_path' => 'archive',
    'link_title' => 'Board Archive',
    'options' => array(
      'identifier' => 'main-menu_board-archive:archive',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Board Archive');

  return $menu_links;
}
