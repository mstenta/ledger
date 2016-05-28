<?php

namespace Drupal\ledger_account\Entity;

use Drupal\views\EntityViewsData;
use Drupal\views\EntityViewsDataInterface;

/**
 * Provides Views data for Ledger Account entities.
 */
class LedgerAccountViewsData extends EntityViewsData implements EntityViewsDataInterface {

  /**
   * {@inheritdoc}
   */
  public function getViewsData() {
    $data = parent::getViewsData();

    $data['ledger_account']['table']['base'] = array(
      'field' => 'id',
      'title' => $this->t('Ledger Account'),
      'help' => $this->t('The Ledger Account ID.'),
    );

    return $data;
  }

}
