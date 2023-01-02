
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

    $children = $this->getChildren();
    $child = $children[$this->childDelta]['class'];

    $class = new $child();
    $class->settings = $this->settings;

    return $class->getContent();
  }

  /**
   * {@inheritdoc}
   */
  function form(&$form, &$form_state) {
    parent::form($form, $form_state);

    $children = $this->getChildren();
    $child = $children[$this->childDelta]['class'];

    $class = new $child();
    $class->form($form, $form_state);

  }

  /**
   * {@inheritdoc}
   */
  function formSubmit($form, &$form_state) {
    parent::formSubmit($form, $form_state);

    $children = $this->getChildren();
    $child = $children[$this->childDelta]['class'];

    $class = new $child();
    $class->formSubmit($form, $form_state);
    $this->settings += $class->settings;
  }

  /**
   * {@inheritdoc}
   */
  function getChildren() {
    return bootstrap_blocks_get_children();
  }
}
