<?php

namespace Drupal\ledger;

use Drupal\Core\Entity\EntityAccessControlHandler;
use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\Core\Access\AccessResult;

/**
 * Access controller for the Ledger entity.
 *
 * @see \Drupal\ledger\Entity\Ledger.
 */
class LedgerAccessControlHandler extends EntityAccessControlHandler {

  /**
   * {@inheritdoc}
   */
  protected function checkAccess(EntityInterface $entity, $operation, AccountInterface $account) {
    /** @var \Drupal\ledger\LedgerInterface $entity */
    switch ($operation) {
      case 'view':
        return AccessResult::allowedIfHasPermission($account, 'view ledger entities');

      case 'update':
        return AccessResult::allowedIfHasPermission($account, 'edit ledger entities');

      case 'delete':
        return AccessResult::allowedIfHasPermission($account, 'delete ledger entities');
    }

    // Unknown operation, no opinion.
    return AccessResult::neutral();
  }

  /**
   * {@inheritdoc}
   */
  protected function checkCreateAccess(AccountInterface $account, array $context, $entity_bundle = NULL) {
    return AccessResult::allowedIfHasPermission($account, 'add ledger entities');
  }

}
