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

    $form['link_style'] = [
      '#type' => 'radios',
      '#title' => t('Vertical tabs'),
      '#options' => array(
        'buttons' => t('Buttons'),
        'tabs' => t('Tabs'),
      ),
      '#default_value' => isset($config['link_style']) ? $config['link_style'] : 0,
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

    $form['tab_id_wrapper'] = [
      '#type' => 'fieldset',
      '#title' => t('Tab block ID'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    ];
    $form['tab_id_wrapper']['tab_id'] = [
      '#type' => 'textfield',
      '#title' => t('Tab ID'),
      '#description' => t('Optional ID. Should be unique.'),
      '#default_value' => isset($config['tab_id']) ? $config['tab_id'] : '',
    ];

  }

  /**
   * {@inheritdoc}
   */
  public function formSubmit($form, &$form_state) {
    $config = $this->settings;

    $values = $form_state['values'];
    dpm($values);

    $this->settings['tabs_padding'] = $values['tabs_padding'];
    $this->settings['tabs_margin'] = $values['tabs_margin'];
    $this->settings['link_style'] = $values['link_style'];
    $this->settings['tab_id'] = $values['tab_id_wrapper']['tab_id'];
    foreach ($values['tabs'] as $index => $tab) {
      if (empty($tab['title']) && empty($tab['content'])) {
        unset($values['tabs'][$index]);
      }
    }
    $this->settings['tabs'] = array_values($values['tabs']);
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
      '#link_style' => $this->settings['link_style'],
      '#tabs' => $this->settings['tabs'],
    ];
  }
}
