<?php

/**
 * Action Card class.
 *
 * @Block(
 * id = "action_card",
 * admin_label = @Translation("Large card with button"),
 * )
 */
class ActionCard extends BootstrapBlock {

  /**
   * {@inheritdoc}
   */
  public function form(&$form, &$form_state) {

    $config = $this->settings;
    $card_title = 'Morbi fermentum amet';
    $card_content = 'Platea dictumst vestibulum rhoncus est pellentesque elit ullamcorper dignissim cras. Dictum sit amet justo donec enim diam vulputate ut. Eu nisl nunc mi ipsum faucibus.';
    $card_tag_url = '#';
    $card_tag = 'Bootstrap';
    $card_date = '07/01/2021';
    $card_signature = 'by Mario Linguito';
    $card_button = 'Action';

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
      '#description' => t('Enter any margin for the card in px.<br>If it is equal to 0 it will not be taken into consideration.<br>Furthermore it will be applied to all edges.'),
      '#default_value' => isset($config['card_margin']) ? $config['card_margin'] : 0,
    ];

    $form['card_date'] = [
      '#type' => 'textfield',
      '#title' => t('Date to show in card:'),
      '#description' => t('Enter the date to show in the card.'),
      '#default_value' => isset($config['card_date']) ? $config['card_date'] : $card_date,
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

    $form['card_tag'] = [
      '#type' => 'textfield',
      '#title' => t('Title of tag:'),
      '#default_value' => isset($config['card_tag']) ? $config['card_tag'] : $card_tag,
    ];

    $form['card_tag_url'] = [
      '#type' => 'textfield',
      '#title' => t('URL of card tag:'),
      '#default_value' => isset($config['card_tag_url']) ? $config['card_tag_url'] : $card_tag_url,
    ];

    $form['card_signature'] = [
      '#type' => 'textfield',
      '#title' => t('Card signature:'),
      '#default_value' => isset($config['card_signature']) ? $config['card_signature'] : $card_signature,
    ];

    $form['card_button'] = [
      '#type' => 'textfield',
      '#title' => t('Card button name:'),
      '#default_value' => isset($config['card_button']) ? $config['card_button'] : $card_button,
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
    $this->settings['card_date'] = $values['card_date'];
    $this->settings['card_title'] = $values['card_title'];
    $this->settings['card_content'] = $values['card_content'];
    $this->settings['card_padding'] = $values['card_padding'];
    $this->settings['card_margin'] = $values['card_margin'];
    $this->settings['card_round'] = $values['card_round'];
    $this->settings['card_tag'] = $values['card_tag'];
    $this->settings['card_tag_url'] = $values['card_tag_url'];
    $this->settings['card_signature'] = $values['card_signature'];
    $this->settings['card_button'] = $values['card_button'];
  }

  /**
   * {@inheritdoc}
   */
  public function getContent() {
    return [
      '#theme' => 'action_card',
      '#card_date' => $this->settings['card_date'],
      '#card_title' => $this->settings['card_title'],
      '#card_content' => $this->settings['card_content'],
      '#card_padding' => $this->settings['card_padding'],
      '#card_margin' => $this->settings['card_margin'],
      '#card_round' => $this->settings['card_round'],
      '#card_tag' => $this->settings['card_tag'],
      '#card_tag_url' => $this->settings['card_tag_url'],
      '#card_signature' => $this->settings['card_signature'],
      '#card_button' => $this->settings['card_button'],
    ];
  }
}
