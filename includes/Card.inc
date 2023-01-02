<?php

/**
 * Card class.
 *
 * @Block(
 * id = "card",
 * admin_label = @Translation("Card"),
 * )
 */
class Card extends BootstrapBlocks {

  /**
   * {@inheritdoc}
   */
  public function form(&$form, &$form_state) {

    $config = $this->settings;
    $card_title = 'Morbi fermentum amet';
    $card_content = 'Platea dictumst vestibulum rhoncus est pellentesque elit ullamcorper dignissim cras. Dictum sit amet justo donec enim diam vulputate ut. Eu nisl nunc mi ipsum faucibus.';
    $card_link_title = 'Read more';
    $card_link_url = '#';

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

    $form['card_title'] = [
      '#type' => 'textfield',
      '#title' => t('Card title:'),
      '#description' => t('Enter a title for this card.'),
      '#default_value' => isset($config['card_title']) ? $config['card_title'] : $card_title,
    ];

    $form['card_content'] = [
      '#type' => 'textarea',
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

    $values = $form_state['values'];
    $pageDepth = $values['page_depth'];

    $this->settings['page_depth'] = $values['page_depth'];
    $this->settings['card_title'] = $values['card_title'];
    $this->settings['card_content'] = $values['card_content'];
    $this->settings['card_padding'] = $values['card_padding'];
    $this->settings['card_margin'] = $values['card_margin'];
    $this->settings['card_round'] = $values['card_round'];
    $this->settings['card_link_title'] = $values['card_link_title'];
    $this->settings['card_link_url'] = $values['card_link_url'];
  }

  /**
   * {@inheritdoc}
   */
  public function getContent() {
    return [
      '#theme' => 'card',
      '#card_title' => $this->settings['card_title'],
      '#card_content' => $this->settings['card_content'],
      '#card_padding' => $this->settings['card_padding'],
      '#card_margin' => $this->settings['card_margin'],
      '#card_round' => $this->settings['card_round'],
      '#card_link_title' => $this->settings['card_link_title'],
      '#card_link_url' => $this->settings['card_link_url'],
    ];
  }
}