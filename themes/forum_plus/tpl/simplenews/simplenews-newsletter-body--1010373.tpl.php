<?php

/**
 * @file
 * Default theme implementation to format the simplenews newsletter body.
 *
 * Copy this file in your theme directory to create a custom themed body.
 * Rename it to override it. Available templates:
 *   simplenews-newsletter-body--[tid].tpl.php
 *   simplenews-newsletter-body--[view mode].tpl.php
 *   simplenews-newsletter-body--[tid]--[view mode].tpl.php
 * See README.txt for more details.
 *
 * Available variables:
 * - $build: Array as expected by render()
 * - $build['#node']: The $node object
 * - $title: Node title
 * - $language: Language code
 * - $view_mode: Active view mode
 * - $simplenews_theme: Contains the path to the configured mail theme.
 * - $simplenews_subscriber: The subscriber for which the newsletter is built.
 *   Note that depending on the used caching strategy, the generated body might
 *   be used for multiple subscribers. If you created personalized newsletters
 *   and can't use tokens for that, make sure to disable caching or write a
 *   custom caching strategy implemention.
 *
 * @see template_preprocess_simplenews_newsletter_body()
 */
?>

<?php
  // Will only print out when content in the minipanel body.
  $output = panels_mini_block_view('swaylocks_weekly_header');
  print $output['content'];
  print_r($build['#node']->body[LANGUAGE_NONE][0]['value']);
?>

<?php
  $view = views_get_view('surfshop');
  $output = $view->preview('panel_pane_3');
  if (!empty($view->result)) {
    print "<h2>" . t('New in the surfshop') . "</h2>";
    print $output;
    print "<p>";
    print '<a class="btn" href="/surfshop">VIEW MORE</a>';
    print "</p>";
    print "<hr />";

  }

  $view = views_get_view('sways_advanced_forum_topic_list');
  $output = $view->preview('panel_pane_3');
  if (!empty($view->result)) {
    print "<h2>" . t('New discussion topics') . "</h2>";
    print $output;
    print "<br />";
    print "<hr />";
  }

  print "<h2>" . t('Active discussion topics') . "</h2>";
  $view = views_get_view('sways_advanced_forum_topic_list');
  $view->set_items_per_page(5);
  print $view->preview('panel_pane_4');
  print "<p>";
  print '<a class="btn" href="/forum/new">VIEW MORE</a>';
  print "</p>";
  print "<hr />";
?>
