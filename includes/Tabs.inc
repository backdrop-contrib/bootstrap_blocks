<?php

/**
 * Tabs class.
 *
 * @Block(
 * id = "tabs",
 * admin_label = @Translation("Cards"),
 * )
 */
class Tabs extends BootstrapBlocks {
  /**
   * {@inheritdoc}
   */
  public function form(&$form, &$form_state) {

    $config = $this->settings;
    $first_tab_title = 'Tab 1';
    $second_tab_title = 'Tab 2';
    $third_tab_title = 'Tab 3';
    $first_tab_content =
      'Platea dictumst vestibulum rhoncus est pellentesque elit ullamcorper dignissim cras. Dictum sit amet justo donec enim diam vulputate ut. Eu nisl nunc mi ipsum faucibus.';
    $second_tab_content =
      'Eget egestas purus viverra accumsan. Diam maecenas ultricies mi eget mauris pharetra et. Etiam dignissim diam quis enim. Eu nisl nunc mi ipsum faucibus.';
    $third_tab_content =
      'Euismod lacinia at quis risus sed vulputate. Scelerisque purus semper eget duis at tellus at urna condimentum. Mattis enim ut tellus elementum sagittis.';
    $first_tab_icon = 'it-link';
    $second_tab_icon = 'it-link';
    $third_tab_icon = 'en-link';

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

    $form['tabs_padding'] = [
      '#type' => 'number',
      '#title' => t('Tabs section padding:'),
      '#description' => t(
        'Enter any padding for the tabs section in px.<br>If it is equal to 0 it will not be taken into consideration.<br>Furthermore it will be applied to all borders. '
      ),
      '#default_value' => isset($config['tabs_padding'])
        ? $config['tabs_padding']
        : 0,
    ];

    $form['tabs_margin'] = [
      '#type' => 'number',
      '#title' => t('Margin of tabs section:'),
      '#description' => t(
        'Enter any margin for the tabs section in px.<br>If it is equal to 0 it will not be taken into consideration.<br>Furthermore it will be applied to all edges. '
      ),
      '#default_value' => isset($config['tabs_margin'])
        ? $config['tabs_margin']
        : 0,
    ];
    if (!isset($form_state['tabs']) && empty($config['tabs'])) {
      $tabs = $form_state['tabs'] = [['title' => '', 'content' => '']];
    }
    elseif (isset($form_state['tabs'])) {
      $tabs = $form_state['tabs'];
    }
    elseif (isset($config['tabs'])) {
      $tabs = $form_state['tabs'] = $config['tabs'];
    }
    dpm($this);

    $form['tabs'] = [
      '#type' => 'container',
      '#title' => t('Tabs'),
       '#id' => 'bootstrap_blocks_tabs_wrapper',
    ];
    foreach ($tabs as $index => $tab) {
      $index++;
      $form['tabs']['tabs' . $index] = [
        '#type' => 'fieldset',
        '#title' => t('Tab ' . $index),
      ];
      $form['tabs']['tabs' . $index]['title'] = [
        '#type' => 'textfield',
        '#title' => t('Title of tab ' . $index),
        '#default_value' => $tab['title'],
      ];

      $form['tabs']['tabs' . $index]['content'] = [
        '#type' => 'textarea',
        '#rows' => 3,
        '#title' => t('Content of tab ' . $index),
        '#default_value' => $tab['content'],
      ];
    }
    $form['add_tab'] = [
      '#type' => 'submit',
      '#submit' => array('bootstrap_blocks_add_tab_submit'),
      '#value' => 'Add tab',
      '#ajax' => array(
        'wrapper' => 'bootstrap_blocks_tabs_wrapper',
        'callback' => 'bootstrap_blocks_add_tab_ajax',
        'effect' => 'slide',
      ),
    ];


  }

  /**
   * {@inheritdoc}
   */
  public function formSubmit($form, &$form_state) {
    $config = $this->settings;

    $values = $form_state['values'];

    $this->settings['page_depth'] = $values['page_depth'];
    $this->settings['tabs_padding'] = $values['tabs_padding'];
    $this->settings['tabs_margin'] = $values['tabs_margin'];
    $this->settings['tabs'] = array_values($values['tabs']);
    dpm($this->settings['tabs']);
  }

  /**
   * {@inheritdoc}
   */
  public function getContent() {
    return [
      '#theme' => 'tabs',
      '#tab_id' => $this->settings['tab_id'],
      '#tabs_padding' => $this->settings['tabs_padding'],
      '#tabs_margin' => $this->settings['tabs_margin'],
      '#first_tab_title' => $this->settings['first_tab_title'],
      '#first_tab_active' => $this->settings['first_tab_active'],
      '#second_tab_title' => $this->settings['second_tab_title'],
      '#second_tab_active' => $this->settings['second_tab_active'],
      '#third_tab_title' => $this->settings['third_tab_title'],
      '#third_tab_active' => $this->settings['third_tab_active'],
      '#first_tab_content' => $this->settings['first_tab_content'],
      '#second_tab_content' => $this->settings['second_tab_content'],
      '#third_tab_content' => $this->settings['third_tab_content'],
      '#first_tab_icon' => $this->settings['first_tab_icon'],
      '#second_tab_icon' => $this->settings['second_tab_icon'],
      '#third_tab_icon' => $this->settings['third_tab_icon'],
    ];
  }
}
