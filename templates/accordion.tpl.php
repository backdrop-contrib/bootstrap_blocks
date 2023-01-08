<?php $tabs_padding = ($tabs_padding > 0) ? 'padding: ' . $tabs_padding . 'px': ''; ?>
<?php $tabs_margin = ($tabs_margin > 0) ? 'margin: ' . $tabs_margin . 'px' : ''; ?>
<?php $bs_parent = ($always_open) ? '' : 'data-bs-parent="#' . $bblock_id . '"'; ?>

<div style="<?php dpm($bs_parent); echo $tabs_padding; ?> <?php echo $tabs_margin; ?>" class="<?php echo $bblock_id; ?> border">
  
  <div class="accordion accordion-flush" id="<?php echo $bblock_id; ?>">
    <?php foreach ($tabs as $delta => $item): ?>
      <div class="accordion-item">
        <h2 class="accordion-header" id="flush-<?php echo $bblock_id; ?>-heading-<?php echo $delta; ?>">
          <button class="accordion-button collapsed" type="button" data-bs-toggle="collapse" data-bs-target="#flush-<?php echo $bblock_id; ?>-collapse-<?php echo $delta; ?>" aria-expanded="false" aria-controls="flush-<?php echo $bblock_id; ?>-collapse-<?php echo $delta; ?>">
            <?php echo $item['title']; ?>
          </button>
        </h2>
        <div id="flush-<?php echo $bblock_id; ?>-collapse-<?php echo $delta; ?>" class="accordion-collapse collapse" aria-labelledby="flush-<?php echo $bblock_id; ?>-heading-<?php echo $delta; ?>" <?php echo $bs_parent; ?>>
          <div class="accordion-body">
            <?php echo $item['content']; ?>
          </div>
        </div>
      </div>
    <?php endforeach; ?>
  </div>
</div>

