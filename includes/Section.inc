<?php

/**
 *Section class.
 *
 * @Block(
 * id = "section",
 * admin_label = @Translation("Section without cards"),
 * )
 */
class Section extends BootstrapBlocks {
  /**
   * {@inheritdoc}
   */
  public function form(&$form, &$form_state) {

    $config = $this->settings;
    $section_title = 'Morbi fermentum amet';
    $first_section =
      'Platea dictumst vestibulum rhoncus est pellentesque elit ullamcorper dignissim cras. Dictum sit amet justo donec enim diam vulputate ut. Eu nisl nunc mi ipsum faucibus.';
    $second_section =
      'Eget egestas purus viverra accumsan. Diam maecenas ultricies mi eget mauris pharetra et. Etiam dignissim diam quis enim. Eu nisl nunc mi ipsum faucibus.';
    $third_section =
      'Euismod lacinia at quis risus sed vulputate. Scelerisque purus semper eget duis at tellus at urna condimentum. Mattis enim ut tellus elementum sagittis.';

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

    $form['section_round'] = [
      '#type' => 'number',
      '#title' => t('Section rounding:'),
      '#description' => t(
        'Enter any rounding for the section in px.<br>If it is equal to 0 it will not be taken into consideration.<br>Furthermore it will be applied to all edges.'
      ),
      '#default_value' => isset($config['section_round'])
        ? $config['section_round']
        : 0,
    ];

    $form['section_padding'] = [
      '#type' => 'number',
      '#title' => t('Section padding:'),
      '#description' => t(
        'Enter any padding for the section in px.<br>If it is equal to 0 it will not be taken into account.<br>Furthermore it will be applied to all borders.'
      ),
      '#default_value' => isset($config['section_padding'])
        ? $config['section_padding']
        : 0,
    ];

    $form['section_margin'] = [
      '#type' => 'number',
      '#title' => t('Section margin:'),
      '#description' => t(
        'Enter any margin for the section in px.<br>If it is equal to 0 it will not be taken into consideration.<br>Furthermore it will be applied to all borders.'
      ),
      '#default_value' => isset($config['section_margin'])
        ? $config['section_margin']
        : 0,
    ];

    $form['section_background'] = [
      '#type' => 'textfield',
      '#title' => t('Possible link for background image:'),
      '#description' => t(
        'A specified image will override the selected color.'
      ),
      '#default_value' => isset($config['section_background'])
        ? $config['section_background']
        : '',
    ];

    $form['section_color'] = [
      '#type' => 'select',
      '#title' => t('Background color:'),
      '#description' => t(
        'Select one of the available background colors.'
      ),
      '#default_value' => isset($config['section_color'])
        ? $config['section_color']
        : '',
      '#options' => [
        'no_color' => 'None',
        'muted' => 'muted',
        'primary' => 'Blue',
        'neutral' => 'Neutral',
      ],
    ];

    $form['section_text_color'] = [
      '#type' => 'textfield',
      '#title' => t('Enter a color for the text:'),
      '#description' => t(
        'If no color code is entered, then the default will be used.'
      ),
      '#default_value' => isset($config['section_text_color'])
        ? $config['section_text_color']
        : '#000000',
    ];

    $form['section_title'] = [
      '#type' => 'textfield',
      '#title' => t('Section title:'),
      '#description' => t('Enter a title for this section.'),
      '#default_value' => isset($config['section_title'])
        ? $config['section_title']
        : $section_title,
    ];

    $form['first_section'] = [
      '#type' => 'textarea',
      '#title' => t('Text of first section:'),
      '#default_value' => isset($config['first_section'])
        ? $config['first_section']
        : $first_section,
    ];

    $form['second_section'] = [
      '#type' => 'textarea',
      '#title' => t('Text of the second section:'),
      '#default_value' => isset($config['second_section'])
        ? $config['second_section']
        : $second_section,
    ];

    $form['third_section'] = [
      '#type' => 'textarea',
      '#title' => t('Text of the third section:'),
      '#default_value' => isset($config['third_section'])
        ? $config['third_section']
        : $third_section,
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
    $this->settings['section_background'] = $helper->translatePath(
      $values['section_background'],
      $pageDepth
    );
    $this->settings['section_color'] = $values['section_color'];
    $this->settings['section_title'] = $values['section_title'];
    $this->settings['first_section'] = $values['first_section'];
    $this->settings['second_section'] = $values['second_section'];
    $this->settings['third_section'] = $values['third_section'];
    $this->settings['section_padding'] = $values['section_padding'];
    $this->settings['section_margin'] = $values['section_margin'];
    $this->settings['section_round'] = $values['section_round'];
    $this->settings['section_text_color'] = $values['section_text_color'];
  }

  /**
   * {@inheritdoc}
   */
  public function getContent() {
    return [
      '#theme' => 'section',
      '#section_background' => $this->settings['section_background'],
      '#section_color' => $this->settings['section_color'],
      '#section_title' => $this->settings['section_title'],
      '#first_section' => $this->settings['first_section'],
      '#second_section' => $this->settings['second_section'],
      '#third_section' => $this->settings['third_section'],
      '#section_padding' => $this->settings['section_padding'],
      '#section_margin' => $this->settings['section_margin'],
      '#section_round' => $this->settings['section_round'],
      '#section_text_color' => $this->settings['section_text_color'],
    ];
  }
}
