<?php

/**
 * @file
 * Class definition of FeedsLedgerGnuCashTransactionProcessor.
 */

/**
 * Creates Ledger Transactions from GnuCash XML.
 */
class FeedsLedgerGnuCashTransactionProcessor extends FeedsLedgerTransactionProcessor {
  
  /**
   * Set a concrete target element. Invoked from FeedsProcessor::map().
   *
   * @ingroup mappingapi
   */
  public function setTargetElement(FeedsSource $source, $target_item, $target_element, $value) {
    switch ($target_element) {
      
      // Timestamp
      // Convert from GnuCash format to Unix timestamp.
      case 'timestamp':
        $target_item->$target_element = strtotime($value);
        break;
      
      // Pass anything else to the parent class's setTargetElement().
      default:
        parent::setTargetElement($source, $target_item, $target_element, $value);
        break;
    }
  }
}