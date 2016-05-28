<?php

namespace Drupal\ledger_account\Entity;

use Drupal\Core\Config\Entity\ConfigEntityBundleBase;
use Drupal\ledger_account\LedgerAccountTypeInterface;

/**
 * Defines the Ledger Account type entity.
 *
 * @ConfigEntityType(
 *   id = "ledger_account_type",
 *   label = @Translation("Ledger Account type"),
 *   handlers = {
 *     "list_builder" = "Drupal\ledger_account\LedgerAccountTypeListBuilder",
 *     "form" = {
 *       "add" = "Drupal\ledger_account\Form\LedgerAccountTypeForm",
 *       "edit" = "Drupal\ledger_account\Form\LedgerAccountTypeForm",
 *       "delete" = "Drupal\ledger_account\Form\LedgerAccountTypeDeleteForm"
 *     },
 *     "route_provider" = {
 *       "html" = "Drupal\ledger_account\LedgerAccountTypeHtmlRouteProvider",
 *     },
 *   },
 *   config_prefix = "ledger_account_type",
 *   admin_permission = "administer site configuration",
 *   bundle_of = "ledger_account",
 *   entity_keys = {
 *     "id" = "id",
 *     "label" = "label",
 *     "uuid" = "uuid"
 *   },
 *   links = {
 *     "canonical" = "/admin/structure/ledger/account/ledger_account_type/{ledger_account_type}",
 *     "add-form" = "/admin/structure/ledger/account/ledger_account_type/add",
 *     "edit-form" = "/admin/structure/ledger/account/ledger_account_type/{ledger_account_type}/edit",
 *     "delete-form" = "/admin/structure/ledger/account/ledger_account_type/{ledger_account_type}/delete",
 *     "collection" = "/admin/structure/ledger/account/ledger_account_type"
 *   }
 * )
 */
class LedgerAccountType extends ConfigEntityBundleBase implements LedgerAccountTypeInterface {

  /**
   * The Ledger Account type ID.
   *
   * @var string
   */
  protected $id;

  /**
   * The Ledger Account type label.
   *
   * @var string
   */
  protected $label;

}
