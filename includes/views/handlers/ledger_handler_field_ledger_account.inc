<?php

/**
 * @file
 * Contains the basic account field handler.
 */

/**
 * Field handler to provide simple renderer that allows linking to an account.
 */
class ledger_handler_field_ledger_account extends views_handler_field {
  function init(&$view, &$options) {
    parent::init($view, $options);

    if ($this->options['link_to_account'] == 'view') {
      $this->additional_fields['aid'] = 'aid';
    }
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['link_to_account'] = array('default' => 'none');

    return $options;
  }

  /**
   * Provide the link to account option.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['link_to_account'] = array(
      '#type' => 'radios',
      '#title' => t('Link this field to'),
      '#description' => t('If the account view page is selected, this will override any other links you have set.'),
      '#options' => array(
        'none' => t('Nothing, unless specified in <em>Rewrite results</em> below'),
        'view' => t('The account view page'),
      ),
      '#default_value' => $this->options['link_to_account'],
    );
  }

  /**
   * Render whatever the data is as a link to the account.
   *
   * Data should be made XSS safe prior to calling this function.
   */
  function render_link($data, $values) {
    if ($this->options['link_to_account'] == 'view' && $data !== NULL && $data !== '') {
      $aid = $this->get_value($values, 'aid');
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = 'admin/ledger/accounts/' . $aid;
    }

    return $data;
  }

  function render($values) {
    $value = $this->get_value($values);
    return $this->render_link($this->sanitize_value($value), $values);
  }
}
