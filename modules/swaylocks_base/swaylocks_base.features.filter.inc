<?php
/**
 * @file
 * swaylocks_base.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function swaylocks_base_filter_default_formats() {
  $formats = array();

  // Exported format: Filtered HTML.
  $formats['filtered_html'] = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -9,
    'editor' => '',
    'editor_settings' => 'a:0:{}',
    'filters' => array(
      'filter_html' => array(
        'weight' => -49,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <u> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <h4> <h5> <h6>  <p> <br> <img> <strike><embed><iframe> <del> <span><video><figure><figcaption>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 1,
        ),
      ),
      'emptyparagraphkiller' => array(
        'weight' => -48,
        'status' => 1,
        'settings' => array(),
      ),
      'quote' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(),
      ),
      'media_filter' => array(
        'weight' => -41,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => -38,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
    ),
  );

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -8,
    'editor' => '',
    'editor_settings' => 'a:0:{}',
    'filters' => array(
      'filter_autop' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(),
      ),
      'pathologic' => array(
        'weight' => -37,
        'status' => 1,
        'settings' => array(
          'settings_source' => 'global',
          'local_paths' => '',
          'protocol_style' => 'full',
          'local_settings' => array(
            'protocol_style' => 'full',
            'local_paths' => '',
          ),
        ),
      ),
    ),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => 1,
    'status' => 1,
    'weight' => -10,
    'editor' => '',
    'editor_settings' => 'a:0:{}',
    'filters' => array(
      'filter_html' => array(
        'weight' => -50,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<img><em> <strong><blockquote> <code> <ul> <ol> <li> <strong> <img> <strong> <blockquote> <p> <em>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 1,
        ),
      ),
      'quote' => array(
        'weight' => -49,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_autop' => array(
        'weight' => -48,
        'status' => 1,
        'settings' => array(),
      ),
      'emptyparagraphkiller' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
