<?php

/**
 * @file
 * Contains the balance field handler.
 */

/**
 * Field handler for balance fields.
 */
class ledger_handler_field_balance extends fraction_handler_field {

  // Sort the results by account entry ID.
  function query() {

    // Execute the parent class's query() method.
    parent::query();

    // If the entity type is not ledger_account or ledger_account_entry, bail.
    $entity_type = 'ledger_account_entry';
    if ($entity_type != 'ledger_account_entry' && $entity_type != 'ledger_account') {
      return;
    }

    // If the entity type is 'ledger_account_entry'...
    if ($entity_type == 'ledger_account_entry') {

      // Join the {ledger_account} table to the {ledger_account_entry} table.
      $join_account = new views_join();
      $join_account->construct('ledger_account', $this->base_table_alias, 'aid', 'aid');
      $this->table_alias_account = $this->query->add_relationship('ledger_account', $join_account, 'ledger_account', $this->base_table_alias);
    }

    // Otherwise, we can assume the type is 'ledger_account'...
    else {

      // The base table is already {ledger_account}.
      $this->table_alias_account = $this->base_table_alias;
    }

    // Join the {ledger_account_type} table to the {ledger_account} table, and fundamental account type..
    $join_account_type = new views_join();
    $join_account_type->construct('ledger_account_type', $this->table_alias_account, 'type', 'type');
    $this->table_alias_account_type = $this->query->ensure_table('ledger_account_type', $this->table_alias_account, $join_account_type);
    $this->account_type_field_alias = $this->query->add_field($this->table_alias_account_type, 'fundamental');

    // Set a custom variable in the query to hold the eid field alias.
    // This will be used in the ledger_transaction_handler_sort_timestamp class to add an additional sort by eid to the View.
    $this->query->ledger_balance_eid_field_alias = $this->field_alias;
  }

  // Reverse the balance sign, if necessary.
  function get_value($values, $field = NULL) {

    // Execute the parent method to get the entity.
    $entity = parent::get_value($values, $field);

    // Pass the numerator and account type into the sign reversing function.
    if (!empty($values->{$this->account_type_field_alias})) {
      $numerator = &$entity->ledger_balance[LANGUAGE_NONE][0]['numerator'];
      $type = $values->{$this->account_type_field_alias};
      ledger_period_sign_reverse($numerator, $type);
    }

    // Return the entity.
    return $entity;
  }
}

