<?php

/**
 * Hero class.
 *
 * @Block(
 * id = "hero",
 * admin_label = @Translation("Classic Hero, with background, and with card"),
 * )
 */
class Hero extends BootstrapBlocks {
  /**
   * {@inheritdoc}
   */
  public function form(&$form, &$form_state) {

    $config = $this->settings;
    $hero_title = 'Morbi fermentum amet';
    $hero_category = 'Category';
    $hero_content =
      'Platea dictumst vestibulum rhoncus est pellentesque elit ullamcorper dignissim cras. Dictum sit amet justo donec enim diam vulputate ut. Eu nisl nunc mi ipsum faucibus.';
    $hero_button_title = 'Read more';
    $hero_button_url = '#';
    $hero_background_url =
      'https://animals.sandiegozoo.org/sites/default/files/2016-08/animals_hero_mountains.jpg';
    $hero_background_alt = 'Background hero';
    $hero_background_title = 'Background hero';
    $hero_card_title =
      'Lorem ipsum dolor sit amet, consectetur adipiscing elit';
    $hero_card_content =
      'Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.';
    $hero_card_link_title = 'Read more';

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

    $form['hero_round'] = [
      '#type' => 'number',
      '#title' => t('Rounding of the hero:'),
      '#description' => t(
        'Enter any rounding for the hero in px.<br>If it is equal to 0 it will not be taken into consideration.<br>Furthermore it will be applied to all edges.'
      ),
      '#default_value' => isset($config['hero_round'])
        ? $config['hero_round']
        : 0,
    ];

    $form['hero_padding'] = [
      '#type' => 'number',
      '#title' => t('Padding of the hero:'),
      '#description' => t(
        'Enter any padding for the hero in px.<br>If it is equal to 0 it will not be taken into consideration.<br>Furthermore it will be applied to all edges.'
      ),
      '#default_value' => isset($config['hero_padding'])
        ? $config['hero_padding']
        : 0,
    ];

    $form['hero_margin'] = [
      '#type' => 'number',
      '#title' => t('Margin of hero:'),
      '#description' => t(
        'Enter any margin for the hero in px.<br>If it is equal to 0 it will not be taken into consideration.<br>Furthermore it will be applied to all borders.'
      ),
      '#default_value' => isset($config['hero_margin'])
        ? $config['hero_margin']
        : 0,
    ];

    $form['hero_category'] = [
      '#type' => 'textfield',
      '#title' => t('Hero category:'),
      '#description' => t('Enter a category for this hero.'),
      '#default_value' => isset($config['hero_category'])
        ? $config['hero_category']
        : $hero_category,
    ];

    $form['hero_title'] = [
      '#type' => 'textfield',
      '#title' => t('Hero title:'),
      '#description' => t('Enter a title for this hero.'),
      '#default_value' => isset($config['hero_title'])
        ? $config['hero_title']
        : $hero_title,
    ];

    $form['hero_content'] = [
      '#type' => 'textarea',
      '#title' => t('Hero text:'),
      '#description' => t('Specify the content of the hero.'),
      '#default_value' => isset($config['hero_content'])
        ? $config['hero_content']
        : $hero_content,
    ];

    $form['hero_button_title'] = [
      '#type' => 'textfield',
      '#title' => t('Button title:'),
      '#default_value' => isset($config['hero_button_title'])
        ? $config['hero_button_title']
        : $hero_button_title,
    ];

    $form['hero_button_url'] = [
      '#type' => 'textfield',
      '#title' => t('Button URL:'),
      '#default_value' => isset($config['hero_button_url'])
        ? $config['hero_button_url']
        : $hero_button_url,
    ];

    $form['hero_background_url'] = [
      '#type' => 'textfield',
      '#title' => t('URL of background image:'),
      '#description' => t(
        'Specify a possible background image, otherwise the primary color will be used.'
      ),
      '#default_value' => isset($config['hero_background_url'])
        ? $config['hero_background_url']
        : $hero_background_url,
    ];

    $form['hero_background_alt'] = [
      '#type' => 'textfield',
      '#title' => t('Alt of background image:'),
      '#description' => t(
        'If a background image is specified, then it is convenient to use an alt.'
      ),
      '#default_value' => isset($config['hero_background_alt'])
        ? $config['hero_background_alt']
        : $hero_background_alt,
    ];

    $form['hero_background_title'] = [
      '#type' => 'textfield',
      '#title' => t('Title of background image:'),
      '#description' => t(
        'If a background image is specified, then it is convenient to use a title.'
      ),
      '#default_value' => isset($config['hero_background_title'])
        ? $config['hero_background_title']
        : $hero_background_title,
    ];

    $form['hero_card_title'] = [
      '#type' => 'textfield',
      '#title' => t('Card title in hero:'),
      '#description' => t(
        'Enter a title for a possible card to add to the component.'
      ),
      '#default_value' => isset($config['hero_card_title'])
        ? $config['hero_card_title']
        : $hero_card_title,
    ];

    $form['hero_card_content'] = [
      '#type' => 'textfield',
      '#title' => t('Content of card in hero:'),
      '#description' => t(
        'Enter content for a possible card to add to the component.'
      ),
      '#default_value' => isset($config['hero_card_content'])
        ? $config['hero_card_content']
        : $hero_card_content,
    ];

    $form['hero_card_link_title'] = [
      '#type' => 'textfield',
      '#title' => t('Link title of card in hero:'),
      '#description' => t(
        'Enter a title for the link for a possible card to add to the component.'
      ),
      '#default_value' => isset($config['hero_card_link_title'])
        ? $config['hero_card_link_title']
        : $hero_card_link_title,
    ];

    $form['hero_card_link_url'] = [
      '#type' => 'textfield',
      '#title' => t('URL of card link in hero:'),
      '#description' => t(
        'Enter a URL for the link for a possible card to add to the component.'
      ),
      '#default_value' => isset($config['hero_card_link_url'])
        ? $config['hero_card_link_url']
        : '#',
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
    $this->settings['hero_title'] = $values['hero_title'];
    $this->settings['hero_content'] = $values['hero_content'];
    $this->settings['hero_padding'] = $values['hero_padding'];
    $this->settings['hero_margin'] = $values['hero_margin'];
    $this->settings['hero_round'] = $values['hero_round'];
    $this->settings['hero_button_title'] = $values['hero_button_title'];
    $this->settings['hero_button_url'] = $values['hero_button_url'];
    $this->settings['hero_category'] = $values['hero_category'];
    $this->settings['hero_background_url'] = $values['hero_background_url'];
    $this->settings['hero_background_alt'] = $values['hero_background_alt'];
    $this->settings['hero_background_title'] = $values['hero_background_title'];
    $this->settings['hero_card_title'] = $values['hero_card_title'];
    $this->settings['hero_card_content'] = $values['hero_card_content'];
    $this->settings['hero_card_link_title'] = $values['hero_card_link_title'];
    $this->settings['hero_card_link_url'] = $values['hero_card_link_url'];
  }

  /**
   * {@inheritdoc}
   */
  public function getContent() {
    return [
      '#theme' => 'hero',
      '#hero_title' => $this->settings['hero_title'],
      '#hero_content' => $this->settings['hero_content'],
      '#hero_padding' => $this->settings['hero_padding'],
      '#hero_margin' => $this->settings['hero_margin'],
      '#hero_round' => $this->settings['hero_round'],
      '#hero_button_title' => $this->settings['hero_button_title'],
      '#hero_button_url' => $this->settings['hero_button_url'],
      '#hero_category' => $this->settings['hero_category'],
      '#hero_background_url' => $this->settings['hero_background_url'],
      '#hero_background_alt' => $this->settings['hero_background_alt'],
      '#hero_background_title' => $this->settings['hero_background_title'],
      '#hero_card_title' => $this->settings['hero_card_title'],
      '#hero_card_content' => $this->settings['hero_card_content'],
      '#hero_card_link_title' => $this->settings['hero_card_link_title'],
      '#hero_card_link_url' => $this->settings['hero_card_link_url'],
    ];
  }
}
