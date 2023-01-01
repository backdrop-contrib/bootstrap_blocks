<div class="row">
  <div class="col-12 col-lg-6">
    <div class="card-wrapper card-space">
      <div class="card card-bg card-big no-after"
           style="
           <?php if (($card_padding > 0)) { ?>
 padding:       <?php echo $card_padding; ?>px; <?php } ?>
 
           <?php if (($card_margin > 0)) { ?>
 margin:        <?php echo $card_margin; ?>px;  <?php } ?>
           <?php if (($card_round > 0)) { ?>
 border-radius: <?php echo $card_round; ?>px;   <?php } ?>
">
        <div class="card-body">
          <div class="head-tags">
            <a class="card-tag" href="<?php echo $card_tag_url; ?>"><?php echo $card_tag; ?></a>
            <span class="data"><?php echo $card_date; ?></span>
          </div>
          <h5 class="card-title"><?php echo $card_title; ?></h5>
          <p class="card-text"><?php echo $card_content; ?></p>
          <div class="it-card-footer">
            <span class="card-signature"><?php echo $card_signature; ?></span>
            <button class="btn btn-outline-primary btn-sm"><?php echo $card_button; ?></button>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>