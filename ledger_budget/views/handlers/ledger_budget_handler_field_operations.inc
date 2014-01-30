<?php

/**
 * @file
 * Field handler to present a list of links to budget operations.
 */
class ledger_budget_handler_field_operations extends ledger_budget_handler_field_link {

  // Alter the field options form.
  function options_form(&$form, &$form_state) {

    // Inherit the parent form.
    parent::options_form($form, $form_state);

    // Unset the 'text' field that was defined by the parent class.
    unset($form['text']);
  }

  // Render the field.
  function render($values) {

    // Ensure the user has access to edit this budget.
    $budget = ledger_budget_new();
    $budget->bid = $this->get_value($values, 'bid');
    if (!ledger_budget_access('update', $budget)) {
      return;
    }

    // Define the operations to include.
    $ops = array(
      l(t('Edit'), 'ledger/budget/' . $budget->bid . '/edit'),
      l(t('Delete'), 'ledger/budget/' . $budget->bid . '/delete'),
    );

    // Assemble the list of operations.
    return implode(' | ', $ops);
  }
}

