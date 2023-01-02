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

    $form['tab_id'] = [
      '#type' => 'textfield',
      '#title' => t('ID of component:'),
      '#description' => t(
        'Enter an ID for the component so that it doesn\'t conflict with another component of the same type.'
      ),
      '#default_value' => isset($config['tab_id']) ? $config['tab_id'] : '',
      '#required' => true,
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

    $form['first_tab_title'] = [
      '#type' => 'textfield',
      '#title' => t('Title of the first tab:'),
      '#description' => t('Enter a title for the first tab.'),
      '#default_value' => isset($config['first_tab_title'])
        ? $config['first_tab_title']
        : $first_tab_title,
    ];

    $form['first_tab_content'] = [
      '#type' => 'textarea',
      '#title' => t('Text of first tab:'),
      '#description' => t(
        'Specify the content of the first section of the tab.'
      ),
      '#default_value' => isset($config['first_tab_content'])
        ? $config['first_tab_content']
        : $first_tab_content,
    ];

    $form['first_tab_active'] = [
      '#type' => 'checkbox',
      '#title' => t('Activate the first tab.'),
      '#description' => t(
        'Select to activate the first tab (it will remain visible but inaccessible).'
      ),
      '#default_value' => isset($config['first_tab_active'])
        ? $config['first_tab_active']
        : true,
    ];

    $form['first_tab_icon'] = [
      '#type' => 'textfield',
      '#title' => t('Icon of the first tab:'),
      '#description' => t(
        'Enter (if any) the name of the icon for this first tab.<br>It must be one that Bootstrap Italia provides.'
      ),
      '#default_value' => isset($config['first_tab_icon'])
        ? $config['first_tab_icon']
        : $first_tab_icon,
    ];

    $form['second_tab_title'] = [
      '#type' => 'textfield',
      '#title' => t('Second tab title:'),
      '#description' => t('Enter a title for the second tab.'),
      '#default_value' => isset($config['second_tab_title'])
        ? $config['second_tab_title']
        : $second_tab_title,
    ];

    $form['second_tab_content'] = [
      '#type' => 'textarea',
      '#title' => t('Text of second tab:'),
      '#description' => t(
        'Specify the content of the second section of the tab.'
      ),
      '#default_value' => isset($config['second_tab_content'])
        ? $config['second_tab_content']
        : $second_tab_content,
    ];

    $form['second_tab_active'] = [
      '#type' => 'checkbox',
      '#title' => t('Activate the second tab.'),
      '#description' => t(
        'Select to activate the second tab (it will remain visible but inaccessible).'
      ),
      '#default_value' => isset($config['second_tab_active'])
        ? $config['second_tab_active']
        : true,
    ];

    $form['second_tab_icon'] = [
      '#type' => 'textfield',
      '#title' => t('Second tab icon:'),
      '#description' => t(
        'Enter (if any) the name of the icon for this second tab.<br>It must be one that Bootstrap Italia provides.'
      ),
      '#default_value' => isset($config['second_tab_icon'])
        ? $config['second_tab_icon']
        : $second_tab_icon,
    ];

    $form['third_tab_title'] = [
      '#type' => 'textfield',
      '#title' => t('Third tab title:'),
      '#description' => t('Enter a title for the third tab.'),
      '#default_value' => isset($config['third_tab_title'])
        ? $config['third_tab_title']
        : $third_tab_title,
    ];

    $form['third_tab_content'] = [
      '#type' => 'textarea',
      '#title' => t('Text of third tab:'),
      '#description' => t(
        'Specify the content of the third section of the tab.'
      ),
      '#default_value' => isset($config['third_tab_content'])
        ? $config['third_tab_content']
        : $third_tab_content,
    ];

    $form['third_tab_active'] = [
      '#type' => 'checkbox',
      '#title' => t('Activate the third tab.'),
      '#description' => t(
        'Select to activate the third tab (it will remain visible but inaccessible).'
      ),
      '#default_value' => isset($config['third_tab_active'])
        ? $config['third_tab_active']
        : true,
    ];

    $form['third_tab_icon'] = [
      '#type' => 'textfield',
      '#title' => t('Third tab icon:'),
      '#description' => t(
        'Enter (if any) the name of the icon for this third tab.<br>It must be one that Bootstrap Italia provides.'
      ),
      '#default_value' => isset($config['third_tab_icon'])
        ? $config['third_tab_icon']
        : $third_tab_icon,
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
    $this->settings['tab_id'] = $values['tab_id'];
    $this->settings['tabs_padding'] = $values['tabs_padding'];
    $this->settings['tabs_margin'] = $values['tabs_margin'];
    $this->settings['first_tab_title'] = $values['first_tab_title'];
    $this->settings['first_tab_active'] = $values['first_tab_active'];
    $this->settings['second_tab_title'] = $values['second_tab_title'];
    $this->settings['second_tab_active'] = $values['second_tab_active'];
    $this->settings['third_tab_title'] = $values['third_tab_title'];
    $this->settings['third_tab_active'] = $values['third_tab_active'];
    $this->settings['first_tab_content'] = $values['first_tab_content'];
    $this->settings['second_tab_content'] = $values['second_tab_content'];
    $this->settings['third_tab_content'] = $values['third_tab_content'];
    $this->settings['first_tab_icon'] = $values['first_tab_icon'];
    $this->settings['second_tab_icon'] = $values['second_tab_icon'];
    $this->settings['third_tab_icon'] = $values['third_tab_icon'];
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
