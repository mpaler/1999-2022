<?php
/**
 * @file
 * swaylocks_search.apachesolr_environments.inc
 */

/**
 * Implements hook_apachesolr_environments().
 */
function swaylocks_search_apachesolr_environments() {
  $export = array();

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'solr';
  $environment->name = 'localhost server';
  $environment->url = 'http://solr.internal:8080/solr';
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_direct_commit' => 0,
    'apachesolr_read_only' => '0',
    'apachesolr_soft_commit' => 0,
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'forum',
      1 => 'glossary',
      2 => 'image',
      3 => 'poll',
      4 => 'surfcraft_archive',
      5 => 'surfshop_non_surfcraft',
      6 => 'surfshop_surfcraft',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
