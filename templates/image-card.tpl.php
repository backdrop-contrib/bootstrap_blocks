<div class="row">
  <div class="col-12 col-lg-6">
    <div class="card-wrapper" 
         style="
          <?php if (($card_padding > 0)) { ?>
 padding: <?php echo $card_padding; ?>px; <?php } ?>
 
          <?php if (($card_margin > 0)) { ?>
 margin:  <?php echo $card_margin; ?>px;  <?php } ?>
">
      <div class="card card-img no-after">
        <div class="img-responsive-wrapper">
          <div class="img-responsive">
            <figure class="img-wrapper">
              <img src="<?php echo $card_image_url; ?>" title="<?php echo $card_image_title; ?>" alt="<?php echo $card_image_alt; ?>">
            </figure>
          </div>
        </div>
        <div class="card-body">
          <h5 class="card-title"><?php echo $card_title; ?></h5>
          <p class="card-text"></p><a class="read-more" href="<?php echo $card_link_url; ?>"><span class="text"><?php echo $card_link_title; ?></span>
            <svg class="icon">
              <use xlink:href="./themes/custom/italiagov/assets/icons/sprite.svg#it-arrow-right"></use>
            </svg></a>
        </div>
      </div>
    </div>
  </div>
</div>