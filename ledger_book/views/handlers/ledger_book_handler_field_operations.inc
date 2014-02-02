<?php

/**
 * @file
 * Field handler to present a list of links to book operations.
 */
class ledger_book_handler_field_operations extends ledger_book_handler_field_link {

  // Alter the field options form.
  function options_form(&$form, &$form_state) {

    // Inherit the parent form.
    parent::options_form($form, $form_state);

    // Unset the 'text' field that was defined by the parent class.
    unset($form['text']);
  }

  // Render the field.
  function render($values) {

    // Ensure the user has access to edit this book.
    $book = ledger_book_load($this->get_value($values, 'bid'));
    if (!ledger_book_access('update', $book)) {
      return;
    }

    // Assemble the link options.
    $options = array();
    if (!empty($this->options['destination'])) {
      $options['query']['destination'] = current_path();
    }

    // Allow other modules to add their operations.
    $ops = module_invoke_all('ledger_book_ops', $book->bid);

    // Add the default edit and delete operations.
    $default_ops = array(
      l(t('Edit'), 'ledger/book/' . $book->bid . '/edit', $options),
      l(t('Delete'), 'ledger/book/' . $book->bid . '/delete', $options),
    );
    $ops = array_merge($ops, $default_ops);

    // Assemble the list of operations.
    return implode(' | ', $ops);
  }
}

