<?php

/**
 * @file
 * Class definition of FeedsLedgerGnuCashAccountProcessor.
 */

/**
 * Creates Ledger Accounts from GnuCash XML.
 */
class FeedsLedgerGnuCashAccountProcessor extends FeedsLedgerAccountProcessor {

  /**
   * Set a concrete target element. Invoked from FeedsProcessor::map().
   *
   * @ingroup mappingapi
   */
  public function setTargetElement(FeedsSource $source, $target_item, $target_element, $value) {
    switch ($target_element) {

      // Account parent
      // This will be a GUID originally, which matches the GUID of a previously imported account. So we need to translate to the account id.
      case 'pid':

        // Start with a no-parent assumption.
        $pid = 0;

        // If a GUID is provided, attempt to look it up in the {feeds_item} table
        if (!empty($value)) {
          $aid = db_query("SELECT entity_id FROM {feeds_item} WHERE guid=:guid", array(':guid' => $value))->fetchField();
          if ($aid) {
            $pid = $aid;
          }
        }

        // Set the target
        $target_item->$target_element = $pid;
        break;

      // Pass anything else to the parent class's setTargetElement().
      default:
        parent::setTargetElement($source, $target_item, $target_element, $value);
        break;
    }
  }
}