<?php

/**
 * @file
 * Field handler to present a list of links to transaction operations.
 */
class ledger_transaction_handler_field_operations extends ledger_transaction_handler_field_link {

  // Alter the field options form.
  function options_form(&$form, &$form_state) {

    // Inherit the parent form.
    parent::options_form($form, $form_state);

    // Unset the 'text' field that was defined by the parent class.
    unset($form['text']);
  }

  // Render the field.
  function render($values) {

    // Ensure the user has access to edit this transaction.
    $transaction = ledger_transaction_new();
    $transaction->tid = $this->get_value($values, 'tid');
    if (!ledger_transaction_access('update', $transaction)) {
      return;
    }

    // Assemble the link options.
    $options = array();
    if (!empty($this->options['destination'])) {
      $options['query']['destination'] = current_path();
    }

    // Define the operations to include.
    $ops = array(
      l(t('Edit'), 'admin/ledger/transactions/' . $transaction->tid . '/edit', $options),
      l(t('Delete'), 'admin/ledger/transactions/' . $transaction->tid . '/delete', $options),
    );

    // Assemble the list of operations.
    return implode(' | ', $ops);
  }
}

