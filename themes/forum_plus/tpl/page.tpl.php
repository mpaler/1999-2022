<?php

/**
 * @file
 * Flatize's theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
?>
<div id="page" <?php print $page_css ?>>
  <?php if(isset($page['show_skins_menu']) && $page['show_skins_menu']):?>
  <?php print $page['show_skins_menu'];?>
  <?php endif;?>

  <?php if($headline = render($page['headline'])): ?>
  <!--
    <section id="headline" class="headline section">
      <div class="container">
        <?php print $headline; ?>
      </div>
    </section>
  -->
  <?php endif;?>

  <header id="header" class="header section mb-4">
    <div class="container">
      <div class="navbar-header">
        <?php print render($page['header']); ?>
      </div>
      <nav class="navbar navbar-expand-lg navbar-dark">
        <a href="<?php print $front_page; ?>" title="<?php print t('Back to Home'); ?>" rel="home" id="logo"
          class="navbar-brand">
          <img src="<?php print $logo; ?>" alt="<?php print t('Back to Home'); ?>">
        </a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav"
          aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
          <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse justify-content-end" id="navbarNav">
          <?php
            $p1 = request_path();
            $p2 = explode('/', $p1);
          ?>

          <ul class="navbar-nav">
            <li class="nav-item">
              <a class="nav-link <?php echo $p2[0] == 'archive' ? " active" : ""; ?>" href="/archive">Board Archive</a>
            </li>
            <li class="nav-item">
              <a class="nav-link <?php echo $p2[0] == 'forum' ? " active" : ""; ?>" href="/forum">Old Forums</a>
            </li>
          </ul>
        </div>
      </nav>
    </div>
  </header>
  <div class="subheader container p-0">
    <?php
      $block = module_invoke('swaylocks_base', 'block_view', 'swaylocks_base_google_search');
      print $block['content'];
    ?>
    <?php print render($page['subheader']); ?>
  </div>
  <?php if ($title && !$is_front): ?>
  <section id="title" class="section-title section">
    <div class="container">
      <?php print render($title_prefix); ?>
      <h1 class="title" id="page-title"><?php print $title; ?></h1>
      <?php print render($title_suffix); ?>
    </div>
  </section>
  <?php endif; ?>

  <?php if ($welcome = render($page['welcome'])): ?>
  <section id="welcome" class="section-title section">
    <div class="container">
      <?php print $welcome;?>
    </div>
  </section>
  <?php endif; ?>

  <?php if($slideshow = render($page['slideshow'])): ?>
  <section id="slideshow" class="slideshow section">
    <div class="container">
      <?php print $slideshow;?>
    </div>
  </section>
  <?php endif;?>

  <?php if($panel_first = render($page['panel_first'])): ?>
  <section id="panel-first" class="panel">
    <div class="container">
      <?php print $panel_first;?>
    </div>
  </section>
  <?php endif; ?>

  <?php if ($messages): ?>
  <section id="messages" class="message section">
    <div class="container">
      <?php print $messages; ?>
    </div>
  </section>
  <?php endif;?>



  <?php if ($breadcrumb): ?>
  <section id="breadcrumb" class="section">
    <div class="container p-0">
      <?php print $breadcrumb; ?>
    </div>
  </section>
  <?php endif; ?>
  <section id="main" class="main section">
    <?php if ($page['highlighted']): ?><div id="highlighted"><?php print render($page['highlighted']); ?></div>
    <?php endif; ?>
    <a id="main-content"></a>
    <div class="container"><?php print render($page['help']); ?></div>
    <div class="container"><?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?>
      </ul><?php endif; ?></div>
    <div class="main-container"><?php print render($page['content']); ?></div>
  </section>
  <?php if($gmap = render($page['gmap'])): ?>
  <section id="gmap">
    <div class="container">
      <?php print $gmap; ?>
    </div>
  </section>
  <?php endif; ?>

  <?php if($panel_second = render($page['panel_second'])): ?>
  <section id="panel-second" class="panel">
    <div class="container">
      <?php print $panel_second;?>
    </div>
  </section>
  <?php endif; ?>

  <?php if($panel_third = render($page['panel_third'])): ?>
  <section id="panel-third" class="panel">
    <div class="container">
      <?php print $panel_third;?>
    </div>
  </section>
  <?php endif; ?>

  <?php if($panel_footer = render($page['panel_footer'])): ?>
  <section id="panel-footer" class="panel">
    <div class="container">
      <?php //print $panel_footer;?>
    </div>
  </section>
  <?php endif; ?>
  <?php if ($tabs): ?>
  <section id="tabs" class="tabs">
    <div class="container">
      <?php print render($tabs); ?>
    </div>
  </section>
  <?php endif; ?>

  <?php if($footer = render($page['footer'])): ?>
  <footer id="footer" class="section">
    <div class="container">
      <?php print $footer; ?>
      <!--?php print $feed_icons; ?-->
    </div>
  </footer>
  <?php endif;?>

  <a title="<?php print t('Back to Top')?>" class="btn-btt" href="#Top"
    style="display: none;"><?php print t('Top')?></a>
</div>