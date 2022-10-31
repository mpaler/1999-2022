<div class="panel-display boxton clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <section id="content-main-wrapper" class="content-main sidebar-first-wrapper">
    <div class="container">
      <div class="row">
        <?php if (!empty($content['content_sidebar_first'])): ?>
          <aside class="sidebar sidebar-first col-md-2">
            <?php print $content['content_sidebar_first']; ?>
          </aside>
        <?php endif; ?>
        <?php if (!empty($content['content_main'])): ?>
          <div class="main-inner col-md-8">
            <?php print $content['content_main']; ?>
          </div>
        <?php endif; ?>
        <?php if(!empty($content['content_sidebar_second'])): ?>
          <aside class="sidebar sidebar-second col-md-2">
            <?php print $content['content_sidebar_second']; ?>
          </aside>
        <?php endif; ?>
      </div>
    </div>
  </section>
</div>
