<?php

/**
 * Complete card class.
 *
 * @Block(
 * id = "complete_card",
 * admin_label = @Translation("Complete large card with icon"),
 * )
 */
class CompleteCard extends BootstrapBlocks {
  /**
   * {@inheritdoc}
   */
  public function form(&$form, &$form_state) {

    $config = $this->settings;
    $card_header = 'Morbi fermentum amet';
    $card_title = 'Morbi fermentum amet';
    $card_content =
      'Platea dictumst vestibulum rhoncus est pellentesque elit ullamcorper dignissim cras. Dictum sit amet justo donec enim diam vulputate ut. Eu nisl nunc mi ipsum faucibus.';
    $card_link_title = 'Read more';
    $card_link_url = '#';
    $card_icon = 'it-card';
    $card_icon_title = 'Development';

    $form['card_round'] = [
      '#type' => 'select',
      '#title' => t('Card rounding:'),
      '#options' => array(0, 1, 2, 3),
      '#description' => t(
        'Enter any rounding for the card border.<br>If it is equal to 0 it will not be taken into consideration.<br>Furthermore it will be applied to all edges.'
      ),
      '#default_value' => isset($config['card_round'])
        ? $config['card_round']
        : 0,
    ];

    $form['card_padding'] = [
      '#type' => 'select',
      '#title' => t('Card padding'),
      '#options' => backdrop_map_assoc(array('0', 1, 2, 3, 4, 5, 'auto')),
      '#description' => t(
        'Enter any padding for the card in px.<br>If it is equal to 0 it will not be taken into consideration.<br>Furthermore it will be applied to all edges.'
      ),
      '#default_value' => isset($config['card_padding'])
        ? $config['card_padding']
        : 3,
    ];

    $form['card_margin'] = [
      '#type' => 'select',
      '#title' => t('Card margin'),
      '#options' => backdrop_map_assoc(array('0', 1, 2, 3, 4, 5, 'auto')),
      '#description' => t(
        'Enter any margin for the card in px.<br>If it is equal to 0 it will not be taken into consideration.<br>Furthermore it will be applied to all borders.'
      ),
      '#default_value' => isset($config['card_margin'])
        ? $config['card_margin']
        : 3,
    ];

    $form['text_align'] = [
      '#type' => 'select',
      '#title' => t('Card text alignment'),
      '#options' => array(
        'left' => t('Left'),
        'right' => t('Right'),
        'center' => t('Center'),
      ),
      '#default_value' => isset($config['text_align'])
        ? $config['text_align']
        : 'left',
    ];

    $form['card_header'] = [
      '#type' => 'textfield',
      '#title' => t('Card header:'),
      '#description' => t('Enter a header title for this card.'),
      '#default_value' => isset($config['card_header'])
        ? $config['card_header']
        : $card_header,
    ];

    $form['card_title'] = [
      '#type' => 'textfield',
      '#title' => t('Card title:'),
      '#description' => t('Enter a title for this card.'),
      '#default_value' => isset($config['card_title'])
        ? $config['card_title']
        : $card_title,
    ];

    $form['card_title_tag'] = [
      '#type' => 'select',
      '#options' => backdrop_map_assoc(array('h1', 'h2', 'h3', 'h4', 'h5', 'h6')),
      '#title' => t('Card title tag'),
      '#description' => t('Choose title tag size.'),
      '#default_value' => isset($config['card_title_tag'])
        ? $config['card_title_tag']
        : 'h5',
    ];

    $form['card_content'] = [
      '#type' => 'textarea',
      '#title' => t('Card text:'),
      '#default_value' => isset($config['card_content'])
        ? $config['card_content']
        : $card_content,
    ];
    $form['card_footer'] = [
      '#type' => 'textarea',
      '#title' => t('Card text:'),
      '#default_value' => isset($config['card_footer'])
        ? $config['card_footer']
        : '',
    ];

  }

  /**
   * {@inheritdoc}
   */
  public function formSubmit($form, &$form_state) {


    $config = $this->settings;

    $values = $form_state['values'];

    $this->settings['card_header'] = $values['card_header'];
    $this->settings['card_title'] = $values['card_title'];
    $this->settings['card_title_tag'] = $values['card_title_tag'];
    $this->settings['card_content'] = $values['card_content'];
    $this->settings['card_footer'] = $values['card_footer'];
    $this->settings['card_padding'] = $values['card_padding'];
    $this->settings['card_margin'] = $values['card_margin'];
    $this->settings['card_round'] = $values['card_round'];
    $this->settings['text_align'] = $values['text_align'];
  }

  /**
   * {@inheritdoc}
   */
  public function getContent() {
    return [
      '#theme' => 'complete_card',
      '#card_header' => $this->settings['card_header'],
      '#card_title' => $this->settings['card_title'],
      '#card_title_tag' => $this->settings['card_title_tag'],
      '#card_content' => $this->settings['card_content'],
      '#card_footer' => $this->settings['card_footer'],
      '#card_padding' => $this->settings['card_padding'],
      '#card_margin' => $this->settings['card_margin'],
      '#card_round' => $this->settings['card_round'],
      '#text_align' => $this->settings['text_align'],
    ];
  }
}
