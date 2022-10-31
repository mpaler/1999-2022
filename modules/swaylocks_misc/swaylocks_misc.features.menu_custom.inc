<?php
/**
 * @file
 * swaylocks_misc.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function swaylocks_misc_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-surfshop-non-surfcraft.
  $menus['menu-surfshop-non-surfcraft'] = array(
    'menu_name' => 'menu-surfshop-non-surfcraft',
    'title' => 'Surfshop Non-surfcraft',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Main menu');
  t('Surfshop Non-surfcraft');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');

  return $menus;
}
