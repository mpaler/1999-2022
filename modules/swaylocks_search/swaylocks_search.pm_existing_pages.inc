<?php
/**
 * @file
 * swaylocks_search.pm_existing_pages.inc
 */

/**
 * Implements hook_pm_existing_pages_info().
 */
function swaylocks_search_pm_existing_pages_info() {
  $export = array();

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'swaylocks_empty_site_search';
  $pm_existing_page->label = 'Swaylock\'s Empty Site Search';
  $pm_existing_page->context = '';
  $pm_existing_page->paths = 'search/site';
  $export['swaylocks_empty_site_search'] = $pm_existing_page;

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'swaylocks_site_search';
  $pm_existing_page->label = 'Swaylock\'s Site Search';
  $pm_existing_page->context = '';
  $pm_existing_page->paths = 'search/site/%';
  $export['swaylocks_site_search'] = $pm_existing_page;

  return $export;
}
