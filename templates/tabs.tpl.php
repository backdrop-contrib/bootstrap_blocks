<?php $tabs_padding = ($tabs_padding > 0) ? 'padding: ' . $tabs_padding . 'px': ''; ?>
<?php $tabs_margin = ($tabs_margin > 0) ? 'margin: ' . $tabs_margin . 'px' : ''; ?>
<?php dpm(get_defined_vars());  $link_style_class = ($link_style == 'buttons') ? 'nav-pills' : 'nav-tabs'; ?>
<?php $tab_id = !empty($tab_id) ? backdrop_clean_css_identifier($tab_id) : 'vtab-block-' . $id; ?>

<div style="<?php echo $tabs_padding; ?> <?php echo $tabs_margin; ?>" class="<?php echo $tab_id; ?> border">
  
  <div class="nav <?php echo $link_style_class; ?>" id="<?php echo $tab_id; ?>" role="tablist">
  <?php foreach ($tabs as $delta => $item): ?>
    <?php $active = ($delta == 0) ? 'active' : ''; ?>
      <button class="nav-link <?php echo $active; ?>" id="tab-<?php echo $delta; ?>" data-bs-toggle="tab" data-bs-target="#tab-content-<?php echo $delta; ?>" role="tab" type="button" aria-controls="tab-content-<?php echo $delta; ?>" aria-selected="true">
      <?php echo $item['title']; ?>
      </button>
    <?php endforeach; ?>
  </div>

  <div class="tab-content" id="<?php echo $tab_id; ?>Content">
  <?php foreach ($tabs as $delta => $item): ?>
    <?php $active = ($delta == 0) ? 'show active' : ''; ?>
    <div class="tab-pane p-4 fade <?php echo $active; ?>" id="tab-content-<?php echo $delta; ?>" role="tabpanel" aria-labelledby="tab-content-<?php echo $delta; ?>-tab"><?php echo $item['content']; ?></div>
    <?php endforeach; ?>
  </div>
</div>

