<?php

/**
 * @file
 * Contains the basic transaction field handler.
 */

/**
 * Field handler to provide simple renderer that allows linking to a transaction.
 */
class ledger_handler_field_ledger_transaction extends views_handler_field {
  function init(&$view, &$options) {
    parent::init($view, $options);

    if ($this->options['link_to_transaction'] == 'view') {
      $this->additional_fields['tid'] = 'tid';
    }
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['link_to_transaction'] = array('default' => 'none');

    return $options;
  }

  /**
   * Provide the link to transaction option.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['link_to_transaction'] = array(
      '#type' => 'radios',
      '#title' => t('Link this field to'),
      '#description' => t('If the transaction view page is selected, this will override any other links you have set.'),
      '#options' => array(
        'none' => t('Nothing, unless specified in <em>Rewrite results</em> below'),
        'view' => t('The transaction view page'),
      ),
      '#default_value' => $this->options['link_to_transaction'],
    );
  }

  /**
   * Render whatever the data is as a link to the transaction.
   *
   * Data should be made XSS safe prior to calling this function.
   */
  function render_link($data, $values) {
    if ($this->options['link_to_transaction'] == 'view' && $data !== NULL && $data !== '') {
      $tid = $this->get_value($values, 'tid');
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = 'ledger/transaction/' . $tid;
    }

    return $data;
  }

  function render($values) {
    $value = $this->get_value($values);
    return $this->render_link($this->sanitize_value($value), $values);
  }
}
