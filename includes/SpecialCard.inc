<?php

/**
 * Special card class.
 *
 * @Block(
 * id = "special_card",
 * admin_label = @Translation("Special card with image"),
 * )
 */
class SpecialCard extends BootstrapBlock {
  /**
   * {@inheritdoc}
   */
  public function form(&$form, &$form_state) {

    $config = $this->settings;
    $card_title = 'Morbi fermentum amet';
    $card_image_url = 'https://picsum.photos/1280/720?image=811';
    $card_image_title = 'Image';
    $card_image_alt = 'Image';
    $card_link_title = 'Read more';
    $card_link_url = '#';
    $card_date = '07/01/2021';

    $form['page_depth'] = [
      '#type' => 'number',
      '#title' => t('Page level (only in case of other languages):'),
      '#description' => t(
        'For example if /page/services, the service level is 2.'
      ),
      '#default_value' => isset($config['page_depth'])
        ? $config['page_depth']
        : 1,
    ];

    $form['card_padding'] = [
      '#type' => 'number',
      '#title' => t('Card padding:'),
      '#description' => t(
        'Enter any padding for the card in px.<br>If it is equal to 0 it will not be taken into consideration.<br>Furthermore it will be applied to all edges.'
      ),
      '#default_value' => isset($config['card_padding'])
        ? $config['card_padding']
        : 0,
    ];

    $form['card_margin'] = [
      '#type' => 'number',
      '#title' => t('Card margin:'),
      '#description' => t(
        'Enter any margin for the card in px.<br>If it is equal to 0 it will not be taken into consideration.<br>Furthermore it will be applied to all edges.'
      ),
      '#default_value' => isset($config['card_margin'])
        ? $config['card_margin']
        : 0,
    ];

    $form['card_title'] = [
      '#type' => 'textfield',
      '#title' => t('Card title:'),
      '#description' => t('Enter a title for this card.'),
      '#default_value' => isset($config['card_title'])
        ? $config['card_title']
        : $card_title,
    ];

    $form['card_date'] = [
      '#type' => 'textfield',
      '#title' => t('Card date:'),
      '#description' => t('Enter a date to show on the card.'),
      '#default_value' => isset($config['card_date'])
        ? $config['card_date']
        : $card_date,
    ];

    $form['card_image_title'] = [
      '#type' => 'textfield',
      '#title' => t('Image title:'),
      '#description' => t('Specify a title for the image.'),
      '#default_value' => isset($config['card_image_title'])
        ? $config['card_image_title']
        : $card_image_title,
    ];

    $form['card_image_alt'] = [
      '#type' => 'textfield',
      '#title' => t('Image alt:'),
      '#description' => t('Specify alternative text for the image.'),
      '#default_value' => isset($config['card_image_alt'])
        ? $config['card_image_alt']
        : $card_image_alt,
    ];

    $form['card_image_url'] = [
      '#type' => 'textfield',
      '#title' => t('Card image link:'),
      '#default_value' => isset($config['card_image_url'])
        ? $config['card_image_url']
        : $card_image_url,
    ];

    $form['card_link_url'] = [
      '#type' => 'textfield',
      '#title' => t('Link URL:'),
      '#default_value' => isset($config['card_link_url'])
        ? $config['card_link_url']
        : $card_link_url,
    ];

  }

  /**
   * {@inheritdoc}
   */
  public function formSubmit($form, &$form_state) {


    $config = $this->settings;
    $helper = new HelperController();
    $values = $form_state['values'];
    $pageDepth = $values['page_depth'];

    $this->configuration['page_depth'] = $values['page_depth'];
    $this->configuration['card_title'] = $values['card_title'];
    $this->configuration['card_date'] = $values['card_date'];
    $this->configuration['card_image_url'] = $values['card_image_url'];
    $this->configuration['card_padding'] = $values['card_padding'];
    $this->configuration['card_margin'] = $values['card_margin'];
    $this->configuration['card_image_title'] = $values['card_image_title'];
    $this->configuration['card_image_alt'] = $values['card_image_alt'];
    $this->configuration['card_link_url'] = $values['card_link_url'];
  }

  /**
   * {@inheritdoc}
   */
  public function build() {
    return [
      '#theme' => 'special_card',
      '#card_title' => $this->configuration['card_title'],
      '#card_date' => $this->configuration['card_date'],
      '#card_image_url' => $this->configuration['card_image_url'],
      '#card_padding' => $this->configuration['card_padding'],
      '#card_margin' => $this->configuration['card_margin'],
      '#card_image_alt' => $this->configuration['card_image_alt'],
      '#card_image_title' => $this->configuration['card_image_title'],
      '#card_link_url' => $this->configuration['card_link_url'],
    ];
  }
}
