
<?php

/**
 * PageComponents extends Block
 *
 * This class allows us to display the page title, local task tabs, 
 * local actions links, and messages in a block.
 */
class BootstrapBlock extends Block {
  protected $page_title = '';

  /**
   * Special function for PageComponents. Sets the page title to be used.
   */
  function setPageTitle($page_title) {
    $this->page_title = $page_title;
  }

  /**
   * {@inheritdoc}
   */
  function getAdminTitle() {
    if (!empty($this->settings['admin_label'])) {
      return check_plain($this->settings['admin_label']);
    }

    $children = $this->getChildren();
    $title = $children[$this->childDelta]['info'];
    return strlen($this->settings['title']) ? check_plain($this->settings['title']) : $title;
  }

  /**
   * {@inheritdoc}
   */
  function getContent() {
    if ($this->childDelta == 'title_combo' || $this->childDelta == 'title' && isset($this->page_title)) {
      $this->settings['title'] = $this->page_title;
    }

    $output = theme('page_components', array('child_delta' => $this->childDelta, 'settings' => $this->settings));

    // Check for any non-space contents. A hidden page title may show nothing
    // at all and the whole block should be hidden in such a case.
    if (strlen(trim($output)) === 0) {
      return NULL;
    }
    return $output;;
  }

  /**
   * {@inheritdoc}
   */
  function form(&$form, &$form_state) {
    parent::form($form, $form_state);
    $form['title_display']['#access'] = FALSE;
    $children = $this->getChildren();
    $child = $children[$this->childDelta]['class'];

    $class = new $child('bootsrap_blocks:bootstrap_blocks' . $this->childDelta);
    $class->form($form, $form_state);

  }

  /**
   * {@inheritdoc}
   */
  function formSubmit($form, &$form_state) {
    parent::formSubmit($form, $form_state);

    // This block never displays a block title, as it would result in things
    // like a title on the title component.
    $this->settings['title_display'] = LAYOUT_TITLE_NONE;
    $this->settings['title'] = '';

    if (isset($form_state['values']['title_wrapper']['title_tag'])) {
      $this->settings['title_tag'] = $form_state['values']['title_wrapper']['title_tag'];
    }
    if (isset($form_state['values']['title_wrapper']['title_classes'])) {
      $this->settings['title_classes'] = $form_state['values']['title_wrapper']['title_classes'];
    }
    if (isset($form_state['values']['tabs']['tab_type'])) {
      $this->settings['tab_type'] = $form_state['values']['tabs']['tab_type'];
    }
  }

  /**
   * {@inheritdoc}
   */
  function getChildren() {
    return bootstrap_blocks_get_children();
  }
}
