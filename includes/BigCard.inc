<?php

/**
 * Big Card class.
 *
 * @Block(
 * id = "big_card",
 * admin_label = @Translation("Big card with icon"),
 * )
 */
class BigCard extends BootstrapBlock {

  /**
   * {@inheritdoc}
   */
  public function form(&$form, &$form_state) {

    $config = $this->settings;
    $card_title = 'Morbi fermentum amet';
    $card_content = 'Platea dictumst vestibulum rhoncus est pellentesque elit ullamcorper dignissim cras. Dictum sit amet justo donec enim diam vulputate ut. Eu nisl nunc mi ipsum faucibus.';
    $card_link_title = 'Read more';
    $card_link_url = '#';
    $card_icon = 'it-card';

    $form['page_depth'] = [
      '#type' => 'number',
      '#title' => t('Page level (only in case of other languages):'),
      '#description' => t('For example if /page/services, the service level is 2.'),
      '#default_value' => isset($config['page_depth']) ? $config['page_depth'] : 1,
    ];

    $form['card_round'] = [
      '#type' => 'number',
      '#title' => t('Card rounding:'),
      '#description' => t('Enter any rounding for the card in px.<br>If it is equal to 0 it will not be taken into consideration.<br>Furthermore it will be applied to all edges.'),
      '#default_value' => isset($config['card_round']) ? $config['card_round'] : 0,
    ];

    $form['card_padding'] = [
      '#type' => 'number',
      '#title' => t('Card padding:'),
      '#description' => t('Enter any padding for the card in px.<br>If it is equal to 0 it will not be taken into consideration.<br>Furthermore it will be applied to all edges.'),
      '#default_value' => isset($config['card_padding']) ? $config['card_padding'] : 0,
    ];

    $form['card_margin'] = [
      '#type' => 'number',
      '#title' => t('Card margin:'),
      '#description' => t('Enter any margin for the card in px.<br>If it is equal to 0 it will not be taken into consideration.<br>Furthermore it will be applied to all borders.'),
      '#default_value' => isset($config['card_margin']) ? $config['card_margin'] : 0,
    ];

    $form['card_icon'] = [
      '#type' => 'textfield',
      '#title' => t('Card icon:'),
      '#description' => t('Enter the name of the icon for this card.<br>It must be one that Bootstrap Italia provides.'),
      '#default_value' => isset($config['card_icon']) ? $config['card_icon'] : $card_icon,
    ];

    $form['card_title'] = [
      '#type' => 'textfield',
      '#title' => t('Card title:'),
      '#description' => t('Enter a title for this card.'),
      '#default_value' => isset($config['card_title']) ? $config['card_title'] : $card_title,
    ];

    $form['card_content'] = [
      '#type' => 'text area',
      '#title' => t('Card text:'),
      '#default_value' => isset($config['card_content']) ? $config['card_content'] : $card_content,
    ];

    $form['card_link_title'] = [
      '#type' => 'textfield',
      '#title' => t('Link title:'),
      '#default_value' => isset($config['card_link_title']) ? $config['card_link_title'] : $card_link_title,
    ];

    $form['card_link_url'] = [
      '#type' => 'textfield',
      '#title' => t('Link URL:'),
      '#default_value' => isset($config['card_link_url']) ? $config['card_link_url'] : $card_link_url,
    ];

  }

  /**
   * {@inheritdoc}
   */
  public function formSubmit($form, &$form_state) {


    $config = $this->settings;
    $helper = new HelperController();
    $values = $form_state->getValues();
    $pageDepth = $values['page_depth'];

    $this->configuration['page_depth'] = $values['page_depth'];
    $this->configuration['card_icon'] = $values['card_icon'];
    $this->configuration['card_title'] = $values['card_title'];
    $this->configuration['card_content'] = $values['card_content'];
    $this->configuration['card_padding'] = $values['card_padding'];
    $this->configuration['card_margin'] = $values['card_margin'];
    $this->configuration['card_round'] = $values['card_round'];
    $this->configuration['card_link_title'] = $values['card_link_title'];
    $this->configuration['card_link_url'] = $values['card_link_url'];
  }

  /**
   * {@inheritdoc}
   */
  public function build() {
    return [
      '#theme' => 'big_card',
      '#card_icon' => $this->configuration['card_icon'],
      '#card_title' => $this->configuration['card_title'],
      '#card_content' => $this->configuration['card_content'],
      '#card_padding' => $this->configuration['card_padding'],
      '#card_margin' => $this->configuration['card_margin'],
      '#card_round' => $this->configuration['card_round'],
      '#card_link_title' => $this->configuration['card_link_title'],
      '#card_link_url' => $this->configuration['card_link_url'],
    ];
  }
}
