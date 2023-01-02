<?php

/**
 * Two-card class.
 *
 * @Block(
 * id = "two_cards",
 * admin_label = @Translation("Double card"),
 * )
 */
class TwoCards extends BootstrapBlock {
  /**
   * {@inheritdoc}
   */
  public function form(&$form, &$form_state) {

    $config = $this->settings;
    $first_card_title = 'Morbi fermentum amet';
    $first_card_content =
      'Platea dictumst vestibulum rhoncus est pellentesque elit ullamcorper dignissim cras. Dictum sit amet justo donec enim diam vulputate ut. Eu nisl nunc mi ipsum faucibus.';
    $first_card_link_title = 'Read more';
    $first_card_link_url = '#';
    $second_card_title = 'Morbi fermentum amet';
    $second_card_content =
      'Platea dictumst vestibulum rhoncus est pellentesque elit ullamcorper dignissim cras. Dictum sit amet justo donec enim diam vulputate ut. Eu nisl nunc mi ipsum faucibus.';
    $second_card_link_title = 'Read more';
    $second_card_link_url = '#';

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

    $form['card_round'] = [
      '#type' => 'number',
      '#title' => t('Card rounding:'),
      '#description' => t(
        'Enter any rounding for the card in px.<br>If it is equal to 0 it will not be taken into consideration.<br>Furthermore it will be applied to all edges.'
      ),
      '#default_value' => isset($config['card_round'])
        ? $config['card_round']
        : 0,
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
        'Enter any margin for the card in px.<br>If it is equal to 0 it will not be taken into consideration.<br>Furthermore it will be applied to all borders.'
      ),
      '#default_value' => isset($config['card_margin'])
        ? $config['card_margin']
        : 0,
    ];

    $form['first_card_title'] = [
      '#type' => 'textfield',
      '#title' => t('Title of the first card:'),
      '#description' => t('Enter a title for the first card.'),
      '#default_value' => isset($config['first_card_title'])
        ? $config['first_card_title']
        : $first_card_title,
    ];

    $form['first_card_content'] = [
      '#type' => 'text area',
      '#title' => t('Text of the first card:'),
      '#default_value' => isset($config['first_card_content'])
        ? $config['first_card_content']
        : $first_card_content,
    ];

    $form['first_card_link_title'] = [
      '#type' => 'textfield',
      '#title' => t('Link title for first card:'),
      '#default_value' => isset($config['first_card_link_title'])
        ? $config['first_card_link_title']
        : $first_card_link_title,
    ];

    $form['first_card_link_url'] = [
      '#type' => 'textfield',
      '#title' => t('URL of the link for the first card:'),
      '#default_value' => isset($config['first_card_link_url'])
        ? $config['first_card_link_url']
        : $first_card_link_url,
    ];

    $form['second_card_title'] = [
      '#type' => 'textfield',
      '#title' => t('Second card title:'),
      '#description' => t('Enter a title for the second card.'),
      '#default_value' => isset($config['second_card_title'])
        ? $config['second_card_title']
        : $second_card_title,
    ];

    $form['second_card_content'] = [
      '#type' => 'text area',
      '#title' => t('Text of the second card:'),
      '#default_value' => isset($config['second_card_content'])
        ? $config['second_card_content']
        : $second_card_content,
    ];

    $form['second_card_link_title'] = [
      '#type' => 'textfield',
      '#title' => t('Link title for second card:'),
      '#default_value' => isset($config['second_card_link_title'])
        ? $config['second_card_link_title']
        : $second_card_link_title,
    ];

    $form['second_card_link_url'] = [
      '#type' => 'textfield',
      '#title' => t('URL of the link for the second card:'),
      '#default_value' => isset($config['second_card_link_url'])
        ? $config['second_card_link_url']
        : $second_card_link_url,
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
    $this->settings['first_card_title'] = $values['first_card_title'];
    $this->settings['first_card_content'] = $values['first_card_content'];
    $this->settings['second_card_title'] = $values['second_card_title'];
    $this->settings['second_card_content'] =
      $values['second_card_content'];
    $this->settings['card_padding'] = $values['card_padding'];
    $this->settings['card_margin'] = $values['card_margin'];
    $this->settings['card_round'] = $values['card_round'];
    $this->settings['first_card_link_title'] =
      $values['first_card_link_title'];
    $this->settings['first_card_link_url'] =
      $values['first_card_link_url'];
    $this->settings['second_card_link_title'] =
      $values['second_card_link_title'];
    $this->settings['second_card_link_url'] =
      $values['second_card_link_url'];
  }

  /**
   * {@inheritdoc}
   */
  public function getContent() {
    return [
      '#theme' => 'two_cards',
      '#first_card_title' => $this->settings['first_card_title'],
      '#first_card_content' => $this->settings['first_card_content'],
      '#second_card_title' => $this->settings['second_card_title'],
      '#second_card_content' => $this->settings['second_card_content'],
      '#card_padding' => $this->settings['card_padding'],
      '#card_margin' => $this->settings['card_margin'],
      '#card_round' => $this->settings['card_round'],
      '#first_card_link_title' => $this->settings['first_card_link_title'],
      '#first_card_link_url' => $this->settings['first_card_link_url'],
      '#second_card_link_title' =>
        $this->settings['second_card_link_title'],
      '#second_card_link_url' => $this->settings['second_card_link_url'],
    ];
  }
}
