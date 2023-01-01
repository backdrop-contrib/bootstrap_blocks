<div class="card-wrapper card-space"
     style="<?php if (($tabs_padding > 0)) { ?>
 padding: <?php echo $tabs_padding; ?>px; <?php } ?>
 
            <?php if (($tabs_margin > 0)) { ?>
 margin:  <?php echo $tabs_margin; ?>px;  <?php } ?>
">
  <div class="card card-bg">
    <div class="card-body">
      <ul class="nav nav-tabs" id="myTabCard" role="tablist">
        <li class="nav-item">
          <a class="nav-link <?php if ($first_tab_active) { ?>
 active <?php } else { ?>
 disabled <?php } ?>
" id="<?php echo ($tab_id . '1'); ?>-tab" data-toggle="tab" href="#<?php echo ($tab_id . '1'); ?>" role="tab" aria-controls="<?php echo ($tab_id . '1'); ?>" aria-selected="<?php if ($first_tab_active) { ?>
 true <?php } else { ?>
 false <?php } ?>
">
            <?php if ($first_tab_icon) { ?>
              <svg class="icon icon-primary">
                <use xlink:href="./themes/custom/italiagov/assets/icons/sprite.svg#<?php echo $first_tab_icon; ?>"></use>
              </svg>
            <?php } ?>
 <?php echo $first_tab_title; ?>
          </a>
        </li>

        <li class="nav-item">
          <a class="nav-link <?php if (($second_tab_active &&  !$first_tab_active)) { ?>
 active <?php } elseif ( !$second_tab_active) { ?>
 disabled <?php } ?>
" id="<?php echo ($tab_id . '2'); ?>-tab" data-toggle="tab" href="#<?php echo ($tab_id . '2'); ?>" role="tab" aria-controls="<?php echo ($tab_id . '2'); ?>" aria-selected="<?php if (($second_tab_active &&  !$first_tab_active)) { ?>
 true <?php } else { ?>
 false <?php } ?>
">
            <?php if ($second_tab_icon) { ?>
              <svg class="icon icon-primary">
                <use xlink:href="./themes/custom/italiagov/assets/icons/sprite.svg#<?php echo $second_tab_icon; ?>"></use>
              </svg>
            <?php } ?>
 <?php echo $second_tab_title; ?>
          </a>
        </li>

        <li class="nav-item">
          <a class="nav-link <?php if (($third_tab_active && ( !$second_tab_active &&  !$first_tab_active))) { ?>
 active <?php } elseif ( !$third_tab_active) { ?>
 disabled <?php } ?>
" id="<?php echo ($tab_id . '3'); ?>-tab" data-toggle="tab" href="#<?php echo ($tab_id . '3'); ?>" role="tab" aria-controls="<?php echo ($tab_id . '3'); ?>" aria-selected="<?php if (($third_tab_active && ( !$second_tab_active &&  !$first_tab_active))) { ?>
 true <?php } else { ?>
 false <?php } ?>
">
            <?php if ($third_tab_icon) { ?>
              <svg class="icon icon-primary">
                <use xlink:href="./themes/custom/italiagov/assets/icons/sprite.svg#<?php echo $third_tab_icon; ?>"></use>
              </svg>
            <?php } ?>
 <?php echo $third_tab_title; ?>
          </a>
        </li>
      </ul>

      <div class="tab-content" id="myTabCardContent">
        <div class="tab-pane p-4 fade <?php if ($first_tab_active) { ?>
 show active <?php } ?>
" id="<?php echo ($tab_id . '1'); ?>" role="tabpanel" aria-labelledby="<?php echo ($tab_id . '1'); ?>-tab"><?php echo $first_tab_content; ?></div>
        <div class="tab-pane p-4 fade <?php if (($second_tab_active &&  !$first_tab_active)) { ?>
 show active <?php } ?>
" id="<?php echo ($tab_id . '2'); ?>" role="tabpanel" aria-labelledby="<?php echo ($tab_id . '2'); ?>-tab"><?php echo $second_tab_content; ?></div>
        <div class="tab-pane p-4 fade <?php if (($third_tab_active && ( !$second_tab_active &&  !$first_tab_active))) { ?>
 show active <?php } ?>
" id="<?php echo ($tab_id . '3'); ?>" role="tabpanel" aria-labelledby="<?php echo ($tab_id . '3'); ?>-tab"><?php echo $third_tab_content; ?></div>
      </div>
    </div>
  </div>
</div>