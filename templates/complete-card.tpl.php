<div class="row">
  <div class="col-12 col-lg-8">
    <div class="card-wrapper card-space">
      <div class="card card-bg card-big border-bottom-card"
           style="
           <?php if (($card_padding > 0)) { ?>
 padding:       <?php echo $card_padding; ?>px; <?php } ?>
 
           <?php if (($card_margin > 0)) { ?>
 margin:        <?php echo $card_margin; ?>px;  <?php } ?>
           <?php if (($card_round > 0)) { ?>
 border-radius: <?php echo $card_round; ?>px;   <?php } ?>
">
        <div class="flag-icon"></div>
        <div class="etichetta">
          <svg class="icon">
            <use xlink:href="./themes/custom/italiagov/assets/icons/sprite.svg#<?php echo $card_icon; ?>"></use>
          </svg>
          <span><?php echo $card_icon_title; ?></span>
        </div>
        <div class="card-body">
          <h5 class="card-title"><?php echo $card_title; ?></h5>
          <p class="card-text"><?php echo $card_content; ?></p>
          <a class="read-more" href="<?php echo $card_link_url; ?>">
            <span class="text"><?php echo $card_link_title; ?></span>
            <svg class="icon">
              <use xlink:href="./themes/custom/italiagov/assets/icons/sprite.svg#it-arrow-right"></use>
            </svg>
          </a>
        </div>
      </div>
    </div>
  </div>
</div>