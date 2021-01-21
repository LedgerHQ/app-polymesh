/*******************************************************************************
*  (c) 2019 Zondax GmbH
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/
#include "substrate_dispatch_V5.h"

#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_system_fill_block_V5(
    parser_context_t* c, pd_system_fill_block_V5_t* m)
{
    CHECK_ERROR(_readPerbill_V5(c, &m->_ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V5(
    parser_context_t* c, pd_system_remark_V5_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->_remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V5(
    parser_context_t* c, pd_system_set_heap_pages_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V5(
    parser_context_t* c, pd_system_set_code_V5_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V5(
    parser_context_t* c, pd_system_set_code_without_checks_V5_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_changes_trie_config_V5(
    parser_context_t* c, pd_system_set_changes_trie_config_V5_t* m)
{
    CHECK_ERROR(_readOptionChangesTrieConfiguration_V5(c, &m->changes_trie_config))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_storage_V5(
    parser_context_t* c, pd_system_set_storage_V5_t* m)
{
    CHECK_ERROR(_readVecKeyValue_V5(c, &m->items))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_storage_V5(
    parser_context_t* c, pd_system_kill_storage_V5_t* m)
{
    CHECK_ERROR(_readVecKey_V5(c, &m->keys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_prefix_V5(
    parser_context_t* c, pd_system_kill_prefix_V5_t* m)
{
    CHECK_ERROR(_readKey_V5(c, &m->prefix))
    CHECK_ERROR(_readu32(c, &m->_subkeys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_suicide_V5(
    parser_context_t* c, pd_system_suicide_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_babe_report_equivocation_V5(
    parser_context_t* c, pd_babe_report_equivocation_V5_t* m)
{
    CHECK_ERROR(_readEquivocationProof_V5(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V5(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_babe_report_equivocation_unsigned_V5(
    parser_context_t* c, pd_babe_report_equivocation_unsigned_V5_t* m)
{
    CHECK_ERROR(_readEquivocationProof_V5(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V5(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V5(
    parser_context_t* c, pd_timestamp_set_V5_t* m)
{
    CHECK_ERROR(_readCompactMoment_V5(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_claim_V5(
    parser_context_t* c, pd_indices_claim_V5_t* m)
{
    CHECK_ERROR(_readAccountIndex_V5(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_transfer_V5(
    parser_context_t* c, pd_indices_transfer_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V5(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_free_V5(
    parser_context_t* c, pd_indices_free_V5_t* m)
{
    CHECK_ERROR(_readAccountIndex_V5(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_force_transfer_V5(
    parser_context_t* c, pd_indices_force_transfer_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V5(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->freeze))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_freeze_V5(
    parser_context_t* c, pd_indices_freeze_V5_t* m)
{
    CHECK_ERROR(_readAccountIndex_V5(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_V5(
    parser_context_t* c, pd_balances_transfer_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_with_memo_V5(
    parser_context_t* c, pd_balances_transfer_with_memo_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    CHECK_ERROR(_readOptionMemo_V5(c, &m->memo))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_deposit_block_reward_reserve_balance_V5(
    parser_context_t* c, pd_balances_deposit_block_reward_reserve_balance_V5_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V5(
    parser_context_t* c, pd_balances_set_balance_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V5(
    parser_context_t* c, pd_balances_force_transfer_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->source))
    CHECK_ERROR(_readLookupSource(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_burn_account_balance_V5(
    parser_context_t* c, pd_balances_burn_account_balance_V5_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_register_did_V5(
    parser_context_t* c, pd_identity_register_did_V5_t* m)
{
    CHECK_ERROR(_readInvestorUid_V5(c, &m->uid))
    CHECK_ERROR(_readVecSecondaryKey_V5(c, &m->secondary_keys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cdd_register_did_V5(
    parser_context_t* c, pd_identity_cdd_register_did_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->target_account))
    CHECK_ERROR(_readVecSecondaryKey_V5(c, &m->secondary_keys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_mock_cdd_register_did_V5(
    parser_context_t* c, pd_identity_mock_cdd_register_did_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->target_account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_invalidate_cdd_claims_V5(
    parser_context_t* c, pd_identity_invalidate_cdd_claims_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->cdd))
    CHECK_ERROR(_readMoment_V5(c, &m->disable_from))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_secondary_keys_V5(
    parser_context_t* c, pd_identity_remove_secondary_keys_V5_t* m)
{
    CHECK_ERROR(_readVecSignatory_V5(c, &m->signers_to_remove))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_accept_primary_key_V5(
    parser_context_t* c, pd_identity_accept_primary_key_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->rotation_auth_id))
    CHECK_ERROR(_readOptionu64(c, &m->optional_cdd_auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_change_cdd_requirement_for_mk_rotation_V5(
    parser_context_t* c, pd_identity_change_cdd_requirement_for_mk_rotation_V5_t* m)
{
    CHECK_ERROR(_readbool(c, &m->auth_required))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_join_identity_as_key_V5(
    parser_context_t* c, pd_identity_join_identity_as_key_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_join_identity_as_identity_V5(
    parser_context_t* c, pd_identity_join_identity_as_identity_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_leave_identity_as_key_V5(
    parser_context_t* c, pd_identity_leave_identity_as_key_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_leave_identity_as_identity_V5(
    parser_context_t* c, pd_identity_leave_identity_as_identity_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->did))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_claim_V5(
    parser_context_t* c, pd_identity_add_claim_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->target))
    CHECK_ERROR(_readClaim_V5(c, &m->claim))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_forwarded_call_V5(
    parser_context_t* c, pd_identity_forwarded_call_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->target_did))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_revoke_claim_V5(
    parser_context_t* c, pd_identity_revoke_claim_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->target))
    CHECK_ERROR(_readClaim_V5(c, &m->claim))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_permission_to_signer_V5(
    parser_context_t* c, pd_identity_set_permission_to_signer_V5_t* m)
{
    CHECK_ERROR(_readSignatory_V5(c, &m->signer))
    CHECK_ERROR(_readPermissions_V5(c, &m->permissions))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_legacy_set_permission_to_signer_V5(
    parser_context_t* c, pd_identity_legacy_set_permission_to_signer_V5_t* m)
{
    CHECK_ERROR(_readSignatory_V5(c, &m->signer))
    CHECK_ERROR(_readLegacyPermissions_V5(c, &m->permissions))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_freeze_secondary_keys_V5(
    parser_context_t* c, pd_identity_freeze_secondary_keys_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_unfreeze_secondary_keys_V5(
    parser_context_t* c, pd_identity_unfreeze_secondary_keys_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_get_my_did_V5(
    parser_context_t* c, pd_identity_get_my_did_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_get_cdd_of_V5(
    parser_context_t* c, pd_identity_get_cdd_of_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->of))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_authorization_V5(
    parser_context_t* c, pd_identity_add_authorization_V5_t* m)
{
    CHECK_ERROR(_readSignatory_V5(c, &m->target))
    CHECK_ERROR(_readAuthorizationData_V5(c, &m->authorization_data))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_authorization_V5(
    parser_context_t* c, pd_identity_remove_authorization_V5_t* m)
{
    CHECK_ERROR(_readSignatory_V5(c, &m->target))
    CHECK_ERROR(_readu64(c, &m->auth_id))
    CHECK_ERROR(_readbool(c, &m->_auth_issuer_pays))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_accept_authorization_V5(
    parser_context_t* c, pd_identity_accept_authorization_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_secondary_keys_with_authorization_V5(
    parser_context_t* c, pd_identity_add_secondary_keys_with_authorization_V5_t* m)
{
    CHECK_ERROR(_readVecSecondaryKeyWithAuth_V5(c, &m->additional_keys))
    CHECK_ERROR(_readMoment_V5(c, &m->expires_at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_revoke_offchain_authorization_V5(
    parser_context_t* c, pd_identity_revoke_offchain_authorization_V5_t* m)
{
    CHECK_ERROR(_readSignatory_V5(c, &m->signer))
    CHECK_ERROR(_readTargetIdAuthorization_V5(c, &m->auth))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_investor_uniqueness_claim_V5(
    parser_context_t* c, pd_identity_add_investor_uniqueness_claim_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->target))
    CHECK_ERROR(_readClaim_V5(c, &m->claim))
    CHECK_ERROR(_readInvestorZKProofData_V5(c, &m->proof))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_gc_add_cdd_claim_V5(
    parser_context_t* c, pd_identity_gc_add_cdd_claim_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->target))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_gc_revoke_cdd_claim_V5(
    parser_context_t* c, pd_identity_gc_revoke_cdd_claim_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_authorship_set_uncles_V5(
    parser_context_t* c, pd_authorship_set_uncles_V5_t* m)
{
    CHECK_ERROR(_readVecHeader(c, &m->new_uncles))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V5(
    parser_context_t* c, pd_staking_bond_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->controller))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readRewardDestination_V5(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V5(
    parser_context_t* c, pd_staking_bond_extra_V5_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->max_additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V5(
    parser_context_t* c, pd_staking_unbond_V5_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V5(
    parser_context_t* c, pd_staking_withdraw_unbonded_V5_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V5(
    parser_context_t* c, pd_staking_validate_V5_t* m)
{
    CHECK_ERROR(_readValidatorPrefs_V5(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V5(
    parser_context_t* c, pd_staking_nominate_V5_t* m)
{
    CHECK_ERROR(_readVecLookupSource(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V5(
    parser_context_t* c, pd_staking_chill_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V5(
    parser_context_t* c, pd_staking_set_payee_V5_t* m)
{
    CHECK_ERROR(_readRewardDestination_V5(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V5(
    parser_context_t* c, pd_staking_set_controller_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V5(
    parser_context_t* c, pd_staking_set_validator_count_V5_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V5(
    parser_context_t* c, pd_staking_increase_validator_count_V5_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_scale_validator_count_V5(
    parser_context_t* c, pd_staking_scale_validator_count_V5_t* m)
{
    CHECK_ERROR(_readPercent_V5(c, &m->factor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_add_permissioned_validator_V5(
    parser_context_t* c, pd_staking_add_permissioned_validator_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->identity))
    CHECK_ERROR(_readOptionu32(c, &m->intended_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_remove_permissioned_validator_V5(
    parser_context_t* c, pd_staking_remove_permissioned_validator_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->identity))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_cdd_expiry_nominators_V5(
    parser_context_t* c, pd_staking_validate_cdd_expiry_nominators_V5_t* m)
{
    CHECK_ERROR(_readVecAccountId_V5(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_commission_cap_V5(
    parser_context_t* c, pd_staking_set_commission_cap_V5_t* m)
{
    CHECK_ERROR(_readPerbill_V5(c, &m->new_cap))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_min_bond_threshold_V5(
    parser_context_t* c, pd_staking_set_min_bond_threshold_V5_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->new_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V5(
    parser_context_t* c, pd_staking_force_no_eras_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V5(
    parser_context_t* c, pd_staking_force_new_era_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V5(
    parser_context_t* c, pd_staking_set_invulnerables_V5_t* m)
{
    CHECK_ERROR(_readVecAccountId_V5(c, &m->validators))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V5(
    parser_context_t* c, pd_staking_force_unstake_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V5(
    parser_context_t* c, pd_staking_force_new_era_always_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V5(
    parser_context_t* c, pd_staking_cancel_deferred_slash_V5_t* m)
{
    CHECK_ERROR(_readEraIndex_V5(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V5(
    parser_context_t* c, pd_staking_payout_stakers_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex_V5(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V5(
    parser_context_t* c, pd_staking_rebond_V5_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_history_depth_V5(
    parser_context_t* c, pd_staking_set_history_depth_V5_t* m)
{
    CHECK_ERROR(_readCompactEraIndex_V5(c, &m->new_history_depth))
    CHECK_ERROR(_readCompactu32(c, &m->_era_items_deleted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V5(
    parser_context_t* c, pd_staking_reap_stash_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_submit_election_solution_V5(
    parser_context_t* c, pd_staking_submit_election_solution_V5_t* m)
{
    CHECK_ERROR(_readVecValidatorIndex_V5(c, &m->winners))
    CHECK_ERROR(_readCompactAssignments_V5(c, &m->compact))
    CHECK_ERROR(_readElectionScore_V5(c, &m->score))
    CHECK_ERROR(_readEraIndex_V5(c, &m->era))
    CHECK_ERROR(_readElectionSize_V5(c, &m->size))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_submit_election_solution_unsigned_V5(
    parser_context_t* c, pd_staking_submit_election_solution_unsigned_V5_t* m)
{
    CHECK_ERROR(_readVecValidatorIndex_V5(c, &m->winners))
    CHECK_ERROR(_readCompactAssignments_V5(c, &m->compact))
    CHECK_ERROR(_readElectionScore_V5(c, &m->score))
    CHECK_ERROR(_readEraIndex_V5(c, &m->era))
    CHECK_ERROR(_readElectionSize_V5(c, &m->size))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_by_system_V5(
    parser_context_t* c, pd_staking_payout_stakers_by_system_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex_V5(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_change_slashing_allowed_for_V5(
    parser_context_t* c, pd_staking_change_slashing_allowed_for_V5_t* m)
{
    CHECK_ERROR(_readSlashingSwitch_V5(c, &m->slashing_switch))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_update_permissioned_validator_intended_count_V5(
    parser_context_t* c, pd_staking_update_permissioned_validator_intended_count_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->identity))
    CHECK_ERROR(_readu32(c, &m->new_intended_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V5(
    parser_context_t* c, pd_session_set_keys_V5_t* m)
{
    CHECK_ERROR(_readKeys_V5(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V5(
    parser_context_t* c, pd_session_purge_keys_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_finalitytracker_final_hint_V5(
    parser_context_t* c, pd_finalitytracker_final_hint_V5_t* m)
{
    CHECK_ERROR(_readCompactBlockNumber(c, &m->hint))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation_V5(
    parser_context_t* c, pd_grandpa_report_equivocation_V5_t* m)
{
    CHECK_ERROR(_readEquivocationProof_V5(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V5(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation_unsigned_V5(
    parser_context_t* c, pd_grandpa_report_equivocation_unsigned_V5_t* m)
{
    CHECK_ERROR(_readEquivocationProof_V5(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V5(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_note_stalled_V5(
    parser_context_t* c, pd_grandpa_note_stalled_V5_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readBlockNumber(c, &m->best_finalized_block_number))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_imonline_heartbeat_V5(
    parser_context_t* c, pd_imonline_heartbeat_V5_t* m)
{
    CHECK_ERROR(_readHeartbeat(c, &m->heartbeat))
    CHECK_ERROR(_readSignature_V5(c, &m->_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_imonline_set_slashing_params_V5(
    parser_context_t* c, pd_imonline_set_slashing_params_V5_t* m)
{
    CHECK_ERROR(_readOfflineSlashingParams_V5(c, &m->params))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_V5(
    parser_context_t* c, pd_sudo_sudo_V5_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_unchecked_weight_V5(
    parser_context_t* c, pd_sudo_sudo_unchecked_weight_V5_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight_V5(c, &m->_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_set_key_V5(
    parser_context_t* c, pd_sudo_set_key_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_as_V5(
    parser_context_t* c, pd_sudo_sudo_as_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->who))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_multisig_V5(
    parser_context_t* c, pd_multisig_create_multisig_V5_t* m)
{
    CHECK_ERROR(_readVecSignatory_V5(c, &m->signers))
    CHECK_ERROR(_readu64(c, &m->sigs_required))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_or_approve_proposal_as_identity_V5(
    parser_context_t* c, pd_multisig_create_or_approve_proposal_as_identity_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->multisig))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->expiry))
    CHECK_ERROR(_readbool(c, &m->auto_close))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_or_approve_proposal_as_key_V5(
    parser_context_t* c, pd_multisig_create_or_approve_proposal_as_key_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->multisig))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->expiry))
    CHECK_ERROR(_readbool(c, &m->auto_close))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_proposal_as_identity_V5(
    parser_context_t* c, pd_multisig_create_proposal_as_identity_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->multisig))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->expiry))
    CHECK_ERROR(_readbool(c, &m->auto_close))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_proposal_as_key_V5(
    parser_context_t* c, pd_multisig_create_proposal_as_key_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->multisig))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->expiry))
    CHECK_ERROR(_readbool(c, &m->auto_close))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_identity_V5(
    parser_context_t* c, pd_multisig_approve_as_identity_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->multisig))
    CHECK_ERROR(_readu64(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_key_V5(
    parser_context_t* c, pd_multisig_approve_as_key_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->multisig))
    CHECK_ERROR(_readu64(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_reject_as_identity_V5(
    parser_context_t* c, pd_multisig_reject_as_identity_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->multisig))
    CHECK_ERROR(_readu64(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_reject_as_key_V5(
    parser_context_t* c, pd_multisig_reject_as_key_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->multisig))
    CHECK_ERROR(_readu64(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_accept_multisig_signer_as_identity_V5(
    parser_context_t* c, pd_multisig_accept_multisig_signer_as_identity_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_accept_multisig_signer_as_key_V5(
    parser_context_t* c, pd_multisig_accept_multisig_signer_as_key_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_add_multisig_signer_V5(
    parser_context_t* c, pd_multisig_add_multisig_signer_V5_t* m)
{
    CHECK_ERROR(_readSignatory_V5(c, &m->signer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_remove_multisig_signer_V5(
    parser_context_t* c, pd_multisig_remove_multisig_signer_V5_t* m)
{
    CHECK_ERROR(_readSignatory_V5(c, &m->signer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_add_multisig_signers_via_creator_V5(
    parser_context_t* c, pd_multisig_add_multisig_signers_via_creator_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->multisig))
    CHECK_ERROR(_readVecSignatory_V5(c, &m->signers))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_remove_multisig_signers_via_creator_V5(
    parser_context_t* c, pd_multisig_remove_multisig_signers_via_creator_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->multisig))
    CHECK_ERROR(_readVecSignatory_V5(c, &m->signers))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_change_sigs_required_V5(
    parser_context_t* c, pd_multisig_change_sigs_required_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->sigs_required))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_make_multisig_signer_V5(
    parser_context_t* c, pd_multisig_make_multisig_signer_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->multisig))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_make_multisig_primary_V5(
    parser_context_t* c, pd_multisig_make_multisig_primary_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->multisig))
    CHECK_ERROR(_readOptionu64(c, &m->optional_cdd_auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_execute_scheduled_proposal_V5(
    parser_context_t* c, pd_multisig_execute_scheduled_proposal_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->multisig))
    CHECK_ERROR(_readu64(c, &m->proposal_id))
    CHECK_ERROR(_readIdentityId_V5(c, &m->multisig_did))
    CHECK_ERROR(_readWeight_V5(c, &m->proposal_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_update_schedule_V5(
    parser_context_t* c, pd_contracts_update_schedule_V5_t* m)
{
    CHECK_ERROR(_readSchedule_V5(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_put_code_V5(
    parser_context_t* c, pd_contracts_put_code_V5_t* m)
{
    CHECK_ERROR(_readTemplateMetadata_V5(c, &m->meta_info))
    CHECK_ERROR(_readBalanceOf(c, &m->instantiation_fee))
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_call_V5(
    parser_context_t* c, pd_contracts_call_V5_t* m)
{
    CHECK_ERROR(_readLookupSource(c, &m->dest))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readCompactGas_V5(c, &m->gas_limit))
    CHECK_ERROR(_readBytes(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_instantiate_V5(
    parser_context_t* c, pd_contracts_instantiate_V5_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->endowment))
    CHECK_ERROR(_readCompactGas_V5(c, &m->gas_limit))
    CHECK_ERROR(_readCodeHash_V5(c, &m->code_hash))
    CHECK_ERROR(_readBytes(c, &m->data))
    CHECK_ERROR(_readBalanceOf(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_freeze_instantiation_V5(
    parser_context_t* c, pd_contracts_freeze_instantiation_V5_t* m)
{
    CHECK_ERROR(_readCodeHash_V5(c, &m->code_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_unfreeze_instantiation_V5(
    parser_context_t* c, pd_contracts_unfreeze_instantiation_V5_t* m)
{
    CHECK_ERROR(_readCodeHash_V5(c, &m->code_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_transfer_template_ownership_V5(
    parser_context_t* c, pd_contracts_transfer_template_ownership_V5_t* m)
{
    CHECK_ERROR(_readCodeHash_V5(c, &m->code_hash))
    CHECK_ERROR(_readIdentityId_V5(c, &m->new_owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_change_template_fees_V5(
    parser_context_t* c, pd_contracts_change_template_fees_V5_t* m)
{
    CHECK_ERROR(_readCodeHash_V5(c, &m->code_hash))
    CHECK_ERROR(_readOptionBalanceOf(c, &m->new_instantiation_fee))
    CHECK_ERROR(_readOptionBalanceOf(c, &m->new_usage_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_change_template_meta_url_V5(
    parser_context_t* c, pd_contracts_change_template_meta_url_V5_t* m)
{
    CHECK_ERROR(_readCodeHash_V5(c, &m->code_hash))
    CHECK_ERROR(_readOptionMetaUrl_V5(c, &m->new_url))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_disbursement_V5(
    parser_context_t* c, pd_treasury_disbursement_V5_t* m)
{
    CHECK_ERROR(_readVecBeneficiary_V5(c, &m->beneficiaries))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reimbursement_V5(
    parser_context_t* c, pd_treasury_reimbursement_V5_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_set_vote_threshold_V5(
    parser_context_t* c, pd_polymeshcommittee_set_vote_threshold_V5_t* m)
{
    CHECK_ERROR(_readu32(c, &m->n))
    CHECK_ERROR(_readu32(c, &m->d))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_set_release_coordinator_V5(
    parser_context_t* c, pd_polymeshcommittee_set_release_coordinator_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_set_expires_after_V5(
    parser_context_t* c, pd_polymeshcommittee_set_expires_after_V5_t* m)
{
    CHECK_ERROR(_readMaybeBlock_V5(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_vote_or_propose_V5(
    parser_context_t* c, pd_polymeshcommittee_vote_or_propose_V5_t* m)
{
    CHECK_ERROR(_readbool(c, &m->approve))
    CHECK_ERROR(_readProposal(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_vote_V5(
    parser_context_t* c, pd_polymeshcommittee_vote_V5_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readProposalIndex_V5(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_set_active_members_limit_V5(
    parser_context_t* c, pd_committeemembership_set_active_members_limit_V5_t* m)
{
    CHECK_ERROR(_readMemberCount_V5(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_disable_member_V5(
    parser_context_t* c, pd_committeemembership_disable_member_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->who))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->expiry))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_add_member_V5(
    parser_context_t* c, pd_committeemembership_add_member_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_remove_member_V5(
    parser_context_t* c, pd_committeemembership_remove_member_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_swap_member_V5(
    parser_context_t* c, pd_committeemembership_swap_member_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->remove))
    CHECK_ERROR(_readIdentityId_V5(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_reset_members_V5(
    parser_context_t* c, pd_committeemembership_reset_members_V5_t* m)
{
    CHECK_ERROR(_readVecIdentityId_V5(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_abdicate_membership_V5(
    parser_context_t* c, pd_committeemembership_abdicate_membership_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_prune_historical_pips_V5(
    parser_context_t* c, pd_pips_set_prune_historical_pips_V5_t* m)
{
    CHECK_ERROR(_readbool(c, &m->prune))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_min_proposal_deposit_V5(
    parser_context_t* c, pd_pips_set_min_proposal_deposit_V5_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->deposit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_default_enactment_period_V5(
    parser_context_t* c, pd_pips_set_default_enactment_period_V5_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_pending_pip_expiry_V5(
    parser_context_t* c, pd_pips_set_pending_pip_expiry_V5_t* m)
{
    CHECK_ERROR(_readMaybeBlock_V5(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_max_pip_skip_count_V5(
    parser_context_t* c, pd_pips_set_max_pip_skip_count_V5_t* m)
{
    CHECK_ERROR(_readSkippedCount_V5(c, &m->max))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_active_pip_limit_V5(
    parser_context_t* c, pd_pips_set_active_pip_limit_V5_t* m)
{
    CHECK_ERROR(_readu32(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_propose_V5(
    parser_context_t* c, pd_pips_propose_V5_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readBalanceOf(c, &m->deposit))
    CHECK_ERROR(_readOptionUrl_V5(c, &m->url))
    CHECK_ERROR(_readOptionPipDescription_V5(c, &m->description))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_vote_V5(
    parser_context_t* c, pd_pips_vote_V5_t* m)
{
    CHECK_ERROR(_readPipId_V5(c, &m->id))
    CHECK_ERROR(_readbool(c, &m->aye_or_nay))
    CHECK_ERROR(_readBalanceOf(c, &m->deposit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_approve_committee_proposal_V5(
    parser_context_t* c, pd_pips_approve_committee_proposal_V5_t* m)
{
    CHECK_ERROR(_readPipId_V5(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_reject_proposal_V5(
    parser_context_t* c, pd_pips_reject_proposal_V5_t* m)
{
    CHECK_ERROR(_readPipId_V5(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_prune_proposal_V5(
    parser_context_t* c, pd_pips_prune_proposal_V5_t* m)
{
    CHECK_ERROR(_readPipId_V5(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_reschedule_execution_V5(
    parser_context_t* c, pd_pips_reschedule_execution_V5_t* m)
{
    CHECK_ERROR(_readPipId_V5(c, &m->id))
    CHECK_ERROR(_readOptionBlockNumber(c, &m->until))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_clear_snapshot_V5(
    parser_context_t* c, pd_pips_clear_snapshot_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_snapshot_V5(
    parser_context_t* c, pd_pips_snapshot_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_enact_snapshot_results_V5(
    parser_context_t* c, pd_pips_enact_snapshot_results_V5_t* m)
{
    CHECK_ERROR(_readVecTuplePipIdSnapshotResult_V5(c, &m->results))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_execute_scheduled_pip_V5(
    parser_context_t* c, pd_pips_execute_scheduled_pip_V5_t* m)
{
    CHECK_ERROR(_readPipId_V5(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_expire_scheduled_pip_V5(
    parser_context_t* c, pd_pips_expire_scheduled_pip_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->did))
    CHECK_ERROR(_readPipId_V5(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_vote_threshold_V5(
    parser_context_t* c, pd_technicalcommittee_set_vote_threshold_V5_t* m)
{
    CHECK_ERROR(_readu32(c, &m->n))
    CHECK_ERROR(_readu32(c, &m->d))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_release_coordinator_V5(
    parser_context_t* c, pd_technicalcommittee_set_release_coordinator_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_expires_after_V5(
    parser_context_t* c, pd_technicalcommittee_set_expires_after_V5_t* m)
{
    CHECK_ERROR(_readMaybeBlock_V5(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_or_propose_V5(
    parser_context_t* c, pd_technicalcommittee_vote_or_propose_V5_t* m)
{
    CHECK_ERROR(_readbool(c, &m->approve))
    CHECK_ERROR(_readProposal(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_V5(
    parser_context_t* c, pd_technicalcommittee_vote_V5_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readProposalIndex_V5(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_set_active_members_limit_V5(
    parser_context_t* c, pd_technicalcommitteemembership_set_active_members_limit_V5_t* m)
{
    CHECK_ERROR(_readMemberCount_V5(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_disable_member_V5(
    parser_context_t* c, pd_technicalcommitteemembership_disable_member_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->who))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->expiry))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_add_member_V5(
    parser_context_t* c, pd_technicalcommitteemembership_add_member_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_remove_member_V5(
    parser_context_t* c, pd_technicalcommitteemembership_remove_member_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_swap_member_V5(
    parser_context_t* c, pd_technicalcommitteemembership_swap_member_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->remove))
    CHECK_ERROR(_readIdentityId_V5(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_reset_members_V5(
    parser_context_t* c, pd_technicalcommitteemembership_reset_members_V5_t* m)
{
    CHECK_ERROR(_readVecIdentityId_V5(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_abdicate_membership_V5(
    parser_context_t* c, pd_technicalcommitteemembership_abdicate_membership_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_set_vote_threshold_V5(
    parser_context_t* c, pd_upgradecommittee_set_vote_threshold_V5_t* m)
{
    CHECK_ERROR(_readu32(c, &m->n))
    CHECK_ERROR(_readu32(c, &m->d))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_set_release_coordinator_V5(
    parser_context_t* c, pd_upgradecommittee_set_release_coordinator_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_set_expires_after_V5(
    parser_context_t* c, pd_upgradecommittee_set_expires_after_V5_t* m)
{
    CHECK_ERROR(_readMaybeBlock_V5(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_vote_or_propose_V5(
    parser_context_t* c, pd_upgradecommittee_vote_or_propose_V5_t* m)
{
    CHECK_ERROR(_readbool(c, &m->approve))
    CHECK_ERROR(_readProposal(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_vote_V5(
    parser_context_t* c, pd_upgradecommittee_vote_V5_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readProposalIndex_V5(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_set_active_members_limit_V5(
    parser_context_t* c, pd_upgradecommitteemembership_set_active_members_limit_V5_t* m)
{
    CHECK_ERROR(_readMemberCount_V5(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_disable_member_V5(
    parser_context_t* c, pd_upgradecommitteemembership_disable_member_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->who))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->expiry))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_add_member_V5(
    parser_context_t* c, pd_upgradecommitteemembership_add_member_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_remove_member_V5(
    parser_context_t* c, pd_upgradecommitteemembership_remove_member_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_swap_member_V5(
    parser_context_t* c, pd_upgradecommitteemembership_swap_member_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->remove))
    CHECK_ERROR(_readIdentityId_V5(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_reset_members_V5(
    parser_context_t* c, pd_upgradecommitteemembership_reset_members_V5_t* m)
{
    CHECK_ERROR(_readVecIdentityId_V5(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_abdicate_membership_V5(
    parser_context_t* c, pd_upgradecommitteemembership_abdicate_membership_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_register_ticker_V5(
    parser_context_t* c, pd_asset_register_ticker_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_accept_ticker_transfer_V5(
    parser_context_t* c, pd_asset_accept_ticker_transfer_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_accept_primary_issuance_agent_transfer_V5(
    parser_context_t* c, pd_asset_accept_primary_issuance_agent_transfer_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_accept_asset_ownership_transfer_V5(
    parser_context_t* c, pd_asset_accept_asset_ownership_transfer_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_create_asset_V5(
    parser_context_t* c, pd_asset_create_asset_V5_t* m)
{
    CHECK_ERROR(_readAssetName_V5(c, &m->name))
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readBalance(c, &m->total_supply))
    CHECK_ERROR(_readbool(c, &m->divisible))
    CHECK_ERROR(_readAssetType_V5(c, &m->asset_type))
    CHECK_ERROR(_readVecAssetIdentifier_V5(c, &m->identifiers))
    CHECK_ERROR(_readOptionFundingRoundName_V5(c, &m->funding_round))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_freeze_V5(
    parser_context_t* c, pd_asset_freeze_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_unfreeze_V5(
    parser_context_t* c, pd_asset_unfreeze_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_rename_asset_V5(
    parser_context_t* c, pd_asset_rename_asset_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readAssetName_V5(c, &m->name))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_issue_V5(
    parser_context_t* c, pd_asset_issue_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_redeem_V5(
    parser_context_t* c, pd_asset_redeem_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_make_divisible_V5(
    parser_context_t* c, pd_asset_make_divisible_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_add_documents_V5(
    parser_context_t* c, pd_asset_add_documents_V5_t* m)
{
    CHECK_ERROR(_readVecDocument_V5(c, &m->docs))
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_remove_documents_V5(
    parser_context_t* c, pd_asset_remove_documents_V5_t* m)
{
    CHECK_ERROR(_readVecDocumentId_V5(c, &m->ids))
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_set_funding_round_V5(
    parser_context_t* c, pd_asset_set_funding_round_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readFundingRoundName_V5(c, &m->name))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_update_identifiers_V5(
    parser_context_t* c, pd_asset_update_identifiers_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readVecAssetIdentifier_V5(c, &m->identifiers))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_add_extension_V5(
    parser_context_t* c, pd_asset_add_extension_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readSmartExtension_V5(c, &m->extension_details))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_archive_extension_V5(
    parser_context_t* c, pd_asset_archive_extension_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readAccountId_V5(c, &m->extension_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_unarchive_extension_V5(
    parser_context_t* c, pd_asset_unarchive_extension_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readAccountId_V5(c, &m->extension_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_remove_primary_issuance_agent_V5(
    parser_context_t* c, pd_asset_remove_primary_issuance_agent_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_remove_smart_extension_V5(
    parser_context_t* c, pd_asset_remove_smart_extension_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readAccountId_V5(c, &m->extension_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_claim_classic_ticker_V5(
    parser_context_t* c, pd_asset_claim_classic_ticker_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readEcdsaSignature_V5(c, &m->ethereum_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_reserve_classic_ticker_V5(
    parser_context_t* c, pd_asset_reserve_classic_ticker_V5_t* m)
{
    CHECK_ERROR(_readClassicTickerImport_V5(c, &m->classic_ticker_import))
    CHECK_ERROR(_readIdentityId_V5(c, &m->contract_did))
    CHECK_ERROR(_readTickerRegistrationConfig_V5(c, &m->config))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_controller_V5(
    parser_context_t* c, pd_bridge_change_controller_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_admin_V5(
    parser_context_t* c, pd_bridge_change_admin_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->admin))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_timelock_V5(
    parser_context_t* c, pd_bridge_change_timelock_V5_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->timelock))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_freeze_V5(
    parser_context_t* c, pd_bridge_freeze_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_unfreeze_V5(
    parser_context_t* c, pd_bridge_unfreeze_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_bridge_limit_V5(
    parser_context_t* c, pd_bridge_change_bridge_limit_V5_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->amount))
    CHECK_ERROR(_readBlockNumber(c, &m->duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_bridge_exempted_V5(
    parser_context_t* c, pd_bridge_change_bridge_exempted_V5_t* m)
{
    CHECK_ERROR(_readVecTupleIdentityIdbool_V5(c, &m->exempted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_force_handle_bridge_tx_V5(
    parser_context_t* c, pd_bridge_force_handle_bridge_tx_V5_t* m)
{
    CHECK_ERROR(_readBridgeTx_V5(c, &m->bridge_tx))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_batch_propose_bridge_tx_V5(
    parser_context_t* c, pd_bridge_batch_propose_bridge_tx_V5_t* m)
{
    CHECK_ERROR(_readVecBridgeTx_V5(c, &m->bridge_txs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_propose_bridge_tx_V5(
    parser_context_t* c, pd_bridge_propose_bridge_tx_V5_t* m)
{
    CHECK_ERROR(_readBridgeTx_V5(c, &m->bridge_tx))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_handle_bridge_tx_V5(
    parser_context_t* c, pd_bridge_handle_bridge_tx_V5_t* m)
{
    CHECK_ERROR(_readBridgeTx_V5(c, &m->bridge_tx))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_freeze_txs_V5(
    parser_context_t* c, pd_bridge_freeze_txs_V5_t* m)
{
    CHECK_ERROR(_readVecBridgeTx_V5(c, &m->bridge_txs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_unfreeze_txs_V5(
    parser_context_t* c, pd_bridge_unfreeze_txs_V5_t* m)
{
    CHECK_ERROR(_readVecBridgeTx_V5(c, &m->bridge_txs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_handle_scheduled_bridge_tx_V5(
    parser_context_t* c, pd_bridge_handle_scheduled_bridge_tx_V5_t* m)
{
    CHECK_ERROR(_readBridgeTx_V5(c, &m->bridge_tx))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_add_compliance_requirement_V5(
    parser_context_t* c, pd_compliancemanager_add_compliance_requirement_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readVecCondition_V5(c, &m->sender_conditions))
    CHECK_ERROR(_readVecCondition_V5(c, &m->receiver_conditions))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_remove_compliance_requirement_V5(
    parser_context_t* c, pd_compliancemanager_remove_compliance_requirement_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_replace_asset_compliance_V5(
    parser_context_t* c, pd_compliancemanager_replace_asset_compliance_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readVecComplianceRequirement_V5(c, &m->asset_compliance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_reset_asset_compliance_V5(
    parser_context_t* c, pd_compliancemanager_reset_asset_compliance_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_pause_asset_compliance_V5(
    parser_context_t* c, pd_compliancemanager_pause_asset_compliance_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_resume_asset_compliance_V5(
    parser_context_t* c, pd_compliancemanager_resume_asset_compliance_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_add_default_trusted_claim_issuer_V5(
    parser_context_t* c, pd_compliancemanager_add_default_trusted_claim_issuer_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readTrustedIssuer_V5(c, &m->issuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_remove_default_trusted_claim_issuer_V5(
    parser_context_t* c, pd_compliancemanager_remove_default_trusted_claim_issuer_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readIdentityId_V5(c, &m->issuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_change_compliance_requirement_V5(
    parser_context_t* c, pd_compliancemanager_change_compliance_requirement_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readComplianceRequirement_V5(c, &m->new_req))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_create_venue_V5(
    parser_context_t* c, pd_settlement_create_venue_V5_t* m)
{
    CHECK_ERROR(_readVenueDetails_V5(c, &m->details))
    CHECK_ERROR(_readVecAccountId_V5(c, &m->signers))
    CHECK_ERROR(_readVenueType_V5(c, &m->venue_type))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_update_venue_V5(
    parser_context_t* c, pd_settlement_update_venue_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->venue_id))
    CHECK_ERROR(_readOptionVenueDetails_V5(c, &m->details))
    CHECK_ERROR(_readOptionVenueType_V5(c, &m->typ))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_add_instruction_V5(
    parser_context_t* c, pd_settlement_add_instruction_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->venue_id))
    CHECK_ERROR(_readSettlementType_V5(c, &m->settlement_type))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->trade_date))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->value_date))
    CHECK_ERROR(_readVecLeg_V5(c, &m->legs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_add_and_affirm_instruction_V5(
    parser_context_t* c, pd_settlement_add_and_affirm_instruction_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->venue_id))
    CHECK_ERROR(_readSettlementType_V5(c, &m->settlement_type))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->trade_date))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->value_date))
    CHECK_ERROR(_readVecLeg_V5(c, &m->legs))
    CHECK_ERROR(_readVecPortfolioId_V5(c, &m->portfolios))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_affirm_instruction_V5(
    parser_context_t* c, pd_settlement_affirm_instruction_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->instruction_id))
    CHECK_ERROR(_readVecPortfolioId_V5(c, &m->portfolios))
    CHECK_ERROR(_readu32(c, &m->max_legs_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_withdraw_affirmation_V5(
    parser_context_t* c, pd_settlement_withdraw_affirmation_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->instruction_id))
    CHECK_ERROR(_readVecPortfolioId_V5(c, &m->portfolios))
    CHECK_ERROR(_readu32(c, &m->max_legs_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_reject_instruction_V5(
    parser_context_t* c, pd_settlement_reject_instruction_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->instruction_id))
    CHECK_ERROR(_readVecPortfolioId_V5(c, &m->portfolios))
    CHECK_ERROR(_readu32(c, &m->max_legs_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_affirm_with_receipts_V5(
    parser_context_t* c, pd_settlement_affirm_with_receipts_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->instruction_id))
    CHECK_ERROR(_readVecReceiptDetails_V5(c, &m->receipt_details))
    CHECK_ERROR(_readVecPortfolioId_V5(c, &m->portfolios))
    CHECK_ERROR(_readu32(c, &m->max_legs_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_claim_receipt_V5(
    parser_context_t* c, pd_settlement_claim_receipt_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->instruction_id))
    CHECK_ERROR(_readReceiptDetails_V5(c, &m->receipt_details))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_unclaim_receipt_V5(
    parser_context_t* c, pd_settlement_unclaim_receipt_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->instruction_id))
    CHECK_ERROR(_readu64(c, &m->leg_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_set_venue_filtering_V5(
    parser_context_t* c, pd_settlement_set_venue_filtering_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readbool(c, &m->enabled))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_allow_venues_V5(
    parser_context_t* c, pd_settlement_allow_venues_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readVecu64(c, &m->venues))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_disallow_venues_V5(
    parser_context_t* c, pd_settlement_disallow_venues_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readVecu64(c, &m->venues))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_execute_scheduled_instruction_V5(
    parser_context_t* c, pd_settlement_execute_scheduled_instruction_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->instruction_id))
    CHECK_ERROR(_readu32(c, &m->legs_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_create_fundraiser_V5(
    parser_context_t* c, pd_sto_create_fundraiser_V5_t* m)
{
    CHECK_ERROR(_readPortfolioId_V5(c, &m->offering_portfolio))
    CHECK_ERROR(_readTicker_V5(c, &m->offering_asset))
    CHECK_ERROR(_readPortfolioId_V5(c, &m->raising_portfolio))
    CHECK_ERROR(_readTicker_V5(c, &m->raising_asset))
    CHECK_ERROR(_readVecPriceTier_V5(c, &m->tiers))
    CHECK_ERROR(_readu64(c, &m->venue_id))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->start))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->end))
    CHECK_ERROR(_readBalance(c, &m->minimum_investment))
    CHECK_ERROR(_readFundraiserName_V5(c, &m->fundraiser_name))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_invest_V5(
    parser_context_t* c, pd_sto_invest_V5_t* m)
{
    CHECK_ERROR(_readPortfolioId_V5(c, &m->investment_portfolio))
    CHECK_ERROR(_readPortfolioId_V5(c, &m->funding_portfolio))
    CHECK_ERROR(_readTicker_V5(c, &m->offering_asset))
    CHECK_ERROR(_readu64(c, &m->fundraiser_id))
    CHECK_ERROR(_readBalance(c, &m->investment_amount))
    CHECK_ERROR(_readOptionBalance(c, &m->max_price))
    CHECK_ERROR(_readOptionReceiptDetails_V5(c, &m->receipt))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_freeze_fundraiser_V5(
    parser_context_t* c, pd_sto_freeze_fundraiser_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->offering_asset))
    CHECK_ERROR(_readu64(c, &m->fundraiser_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_unfreeze_fundraiser_V5(
    parser_context_t* c, pd_sto_unfreeze_fundraiser_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->offering_asset))
    CHECK_ERROR(_readu64(c, &m->fundraiser_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_modify_fundraiser_window_V5(
    parser_context_t* c, pd_sto_modify_fundraiser_window_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->offering_asset))
    CHECK_ERROR(_readu64(c, &m->fundraiser_id))
    CHECK_ERROR(_readMoment_V5(c, &m->start))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->end))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_stop_V5(
    parser_context_t* c, pd_sto_stop_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->offering_asset))
    CHECK_ERROR(_readu64(c, &m->fundraiser_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_set_active_members_limit_V5(
    parser_context_t* c, pd_cddserviceproviders_set_active_members_limit_V5_t* m)
{
    CHECK_ERROR(_readMemberCount_V5(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_disable_member_V5(
    parser_context_t* c, pd_cddserviceproviders_disable_member_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->who))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->expiry))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_add_member_V5(
    parser_context_t* c, pd_cddserviceproviders_add_member_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_remove_member_V5(
    parser_context_t* c, pd_cddserviceproviders_remove_member_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_swap_member_V5(
    parser_context_t* c, pd_cddserviceproviders_swap_member_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->remove))
    CHECK_ERROR(_readIdentityId_V5(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_reset_members_V5(
    parser_context_t* c, pd_cddserviceproviders_reset_members_V5_t* m)
{
    CHECK_ERROR(_readVecIdentityId_V5(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_abdicate_membership_V5(
    parser_context_t* c, pd_cddserviceproviders_abdicate_membership_V5_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_statistics_add_transfer_manager_V5(
    parser_context_t* c, pd_statistics_add_transfer_manager_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readTransferManager_V5(c, &m->new_transfer_manager))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_statistics_remove_transfer_manager_V5(
    parser_context_t* c, pd_statistics_remove_transfer_manager_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readTransferManager_V5(c, &m->transfer_manager))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_statistics_add_exempted_entities_V5(
    parser_context_t* c, pd_statistics_add_exempted_entities_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readTransferManager_V5(c, &m->transfer_manager))
    CHECK_ERROR(_readVecScopeId_V5(c, &m->exempted_entities))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_statistics_remove_exempted_entities_V5(
    parser_context_t* c, pd_statistics_remove_exempted_entities_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readTransferManager_V5(c, &m->transfer_manager))
    CHECK_ERROR(_readVecScopeId_V5(c, &m->entities))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_protocolfee_change_coefficient_V5(
    parser_context_t* c, pd_protocolfee_change_coefficient_V5_t* m)
{
    CHECK_ERROR(_readPosRatio_V5(c, &m->coefficient))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_protocolfee_change_base_fee_V5(
    parser_context_t* c, pd_protocolfee_change_base_fee_V5_t* m)
{
    CHECK_ERROR(_readProtocolOp_V5(c, &m->op))
    CHECK_ERROR(_readBalanceOf(c, &m->base_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V5(
    parser_context_t* c, pd_utility_batch_V5_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_atomic_V5(
    parser_context_t* c, pd_utility_batch_atomic_V5_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_optimistic_V5(
    parser_context_t* c, pd_utility_batch_optimistic_V5_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_relay_tx_V5(
    parser_context_t* c, pd_utility_relay_tx_V5_t* m)
{
    CHECK_ERROR(_readAccountId_V5(c, &m->target))
    CHECK_ERROR(_readOffChainSignature_V5(c, &m->signature))
    CHECK_ERROR(_readUniqueCall_V5(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_create_portfolio_V5(
    parser_context_t* c, pd_portfolio_create_portfolio_V5_t* m)
{
    CHECK_ERROR(_readPortfolioName_V5(c, &m->name))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_delete_portfolio_V5(
    parser_context_t* c, pd_portfolio_delete_portfolio_V5_t* m)
{
    CHECK_ERROR(_readPortfolioNumber_V5(c, &m->num))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_move_portfolio_funds_V5(
    parser_context_t* c, pd_portfolio_move_portfolio_funds_V5_t* m)
{
    CHECK_ERROR(_readPortfolioId_V5(c, &m->from))
    CHECK_ERROR(_readPortfolioId_V5(c, &m->to))
    CHECK_ERROR(_readVecMovePortfolioItem_V5(c, &m->items))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_rename_portfolio_V5(
    parser_context_t* c, pd_portfolio_rename_portfolio_V5_t* m)
{
    CHECK_ERROR(_readPortfolioNumber_V5(c, &m->num))
    CHECK_ERROR(_readPortfolioName_V5(c, &m->to_name))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_confidential_add_range_proof_V5(
    parser_context_t* c, pd_confidential_add_range_proof_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->target_id))
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readu64(c, &m->secret_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_confidential_add_verify_range_proof_V5(
    parser_context_t* c, pd_confidential_add_verify_range_proof_V5_t* m)
{
    CHECK_ERROR(_readIdentityId_V5(c, &m->target))
    CHECK_ERROR(_readIdentityId_V5(c, &m->prover))
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_V5(
    parser_context_t* c, pd_scheduler_schedule_V5_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod_V5(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V5(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_V5(
    parser_context_t* c, pd_scheduler_cancel_V5_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_V5(
    parser_context_t* c, pd_scheduler_schedule_named_V5_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod_V5(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V5(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_named_V5(
    parser_context_t* c, pd_scheduler_cancel_named_V5_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_after_V5(
    parser_context_t* c, pd_scheduler_schedule_after_V5_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionPeriod_V5(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V5(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_after_V5(
    parser_context_t* c, pd_scheduler_schedule_named_after_V5_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionPeriod_V5(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V5(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_set_max_details_length_V5(
    parser_context_t* c, pd_corporateaction_set_max_details_length_V5_t* m)
{
    CHECK_ERROR(_readu32(c, &m->length))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_reset_caa_V5(
    parser_context_t* c, pd_corporateaction_reset_caa_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_set_default_targets_V5(
    parser_context_t* c, pd_corporateaction_set_default_targets_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readTargetIdentities_V5(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_set_default_withholding_tax_V5(
    parser_context_t* c, pd_corporateaction_set_default_withholding_tax_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readTax_V5(c, &m->tax))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_set_did_withholding_tax_V5(
    parser_context_t* c, pd_corporateaction_set_did_withholding_tax_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readIdentityId_V5(c, &m->taxed_did))
    CHECK_ERROR(_readOptionTax_V5(c, &m->tax))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_initiate_corporate_action_V5(
    parser_context_t* c, pd_corporateaction_initiate_corporate_action_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readCAKind_V5(c, &m->kind))
    CHECK_ERROR(_readMoment_V5(c, &m->decl_date))
    CHECK_ERROR(_readOptionRecordDateSpec_V5(c, &m->record_date))
    CHECK_ERROR(_readCADetails_V5(c, &m->details))
    CHECK_ERROR(_readOptionTargetIdentities_V5(c, &m->targets))
    CHECK_ERROR(_readOptionTax_V5(c, &m->default_withholding_tax))
    CHECK_ERROR(_readOptionVecTupleIdentityIdTax_V5(c, &m->withholding_tax))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_link_ca_doc_V5(
    parser_context_t* c, pd_corporateaction_link_ca_doc_V5_t* m)
{
    CHECK_ERROR(_readCAId_V5(c, &m->id))
    CHECK_ERROR(_readVecDocumentId_V5(c, &m->docs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_remove_ca_V5(
    parser_context_t* c, pd_corporateaction_remove_ca_V5_t* m)
{
    CHECK_ERROR(_readCAId_V5(c, &m->ca_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_change_record_date_V5(
    parser_context_t* c, pd_corporateaction_change_record_date_V5_t* m)
{
    CHECK_ERROR(_readCAId_V5(c, &m->ca_id))
    CHECK_ERROR(_readOptionRecordDateSpec_V5(c, &m->record_date))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_attach_ballot_V5(
    parser_context_t* c, pd_corporateballot_attach_ballot_V5_t* m)
{
    CHECK_ERROR(_readCAId_V5(c, &m->ca_id))
    CHECK_ERROR(_readBallotTimeRange_V5(c, &m->range))
    CHECK_ERROR(_readBallotMeta_V5(c, &m->meta))
    CHECK_ERROR(_readbool(c, &m->rcv))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_vote_V5(
    parser_context_t* c, pd_corporateballot_vote_V5_t* m)
{
    CHECK_ERROR(_readCAId_V5(c, &m->ca_id))
    CHECK_ERROR(_readVecBallotVote_V5(c, &m->votes))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_change_end_V5(
    parser_context_t* c, pd_corporateballot_change_end_V5_t* m)
{
    CHECK_ERROR(_readCAId_V5(c, &m->ca_id))
    CHECK_ERROR(_readMoment_V5(c, &m->end))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_change_meta_V5(
    parser_context_t* c, pd_corporateballot_change_meta_V5_t* m)
{
    CHECK_ERROR(_readCAId_V5(c, &m->ca_id))
    CHECK_ERROR(_readBallotMeta_V5(c, &m->meta))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_change_rcv_V5(
    parser_context_t* c, pd_corporateballot_change_rcv_V5_t* m)
{
    CHECK_ERROR(_readCAId_V5(c, &m->ca_id))
    CHECK_ERROR(_readbool(c, &m->rcv))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_remove_ballot_V5(
    parser_context_t* c, pd_corporateballot_remove_ballot_V5_t* m)
{
    CHECK_ERROR(_readCAId_V5(c, &m->ca_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_distribute_V5(
    parser_context_t* c, pd_capitaldistribution_distribute_V5_t* m)
{
    CHECK_ERROR(_readCAId_V5(c, &m->ca_id))
    CHECK_ERROR(_readOptionPortfolioNumber_V5(c, &m->portfolio))
    CHECK_ERROR(_readTicker_V5(c, &m->currency))
    CHECK_ERROR(_readBalance(c, &m->amount))
    CHECK_ERROR(_readMoment_V5(c, &m->payment_at))
    CHECK_ERROR(_readOptionMoment_V5(c, &m->expires_at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_claim_V5(
    parser_context_t* c, pd_capitaldistribution_claim_V5_t* m)
{
    CHECK_ERROR(_readCAId_V5(c, &m->ca_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_push_benefit_V5(
    parser_context_t* c, pd_capitaldistribution_push_benefit_V5_t* m)
{
    CHECK_ERROR(_readCAId_V5(c, &m->ca_id))
    CHECK_ERROR(_readIdentityId_V5(c, &m->holder))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_reclaim_V5(
    parser_context_t* c, pd_capitaldistribution_reclaim_V5_t* m)
{
    CHECK_ERROR(_readCAId_V5(c, &m->ca_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_remove_distribution_V5(
    parser_context_t* c, pd_capitaldistribution_remove_distribution_V5_t* m)
{
    CHECK_ERROR(_readCAId_V5(c, &m->ca_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_checkpoint_create_checkpoint_V5(
    parser_context_t* c, pd_checkpoint_create_checkpoint_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_checkpoint_set_schedules_max_complexity_V5(
    parser_context_t* c, pd_checkpoint_set_schedules_max_complexity_V5_t* m)
{
    CHECK_ERROR(_readu64(c, &m->max_complexity))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_checkpoint_create_schedule_V5(
    parser_context_t* c, pd_checkpoint_create_schedule_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readScheduleSpec_V5(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_checkpoint_remove_schedule_V5(
    parser_context_t* c, pd_checkpoint_remove_schedule_V5_t* m)
{
    CHECK_ERROR(_readTicker_V5(c, &m->ticker))
    CHECK_ERROR(_readScheduleId_V5(c, &m->id))
    return parser_ok;
}

parser_error_t _readMethodBasic_V5(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_MethodBasic_V5_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V5(c, &method->system_fill_block_V5))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V5(c, &method->system_remark_V5))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V5(c, &method->system_set_heap_pages_V5))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V5(c, &method->system_set_code_V5))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V5(c, &method->system_set_code_without_checks_V5))
        break;
    case 5: /* module 0 call 5 */
        CHECK_ERROR(_readMethod_system_set_changes_trie_config_V5(c, &method->system_set_changes_trie_config_V5))
        break;
    case 6: /* module 0 call 6 */
        CHECK_ERROR(_readMethod_system_set_storage_V5(c, &method->system_set_storage_V5))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_kill_storage_V5(c, &method->system_kill_storage_V5))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_kill_prefix_V5(c, &method->system_kill_prefix_V5))
        break;
    case 9: /* module 0 call 9 */
        CHECK_ERROR(_readMethod_system_suicide_V5(c, &method->system_suicide_V5))
        break;
    case 256: /* module 1 call 0 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_V5(c, &method->babe_report_equivocation_V5))
        break;
    case 257: /* module 1 call 1 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_unsigned_V5(c, &method->babe_report_equivocation_unsigned_V5))
        break;
    case 512: /* module 2 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V5(c, &method->timestamp_set_V5))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_indices_claim_V5(c, &method->indices_claim_V5))
        break;
    case 769: /* module 3 call 1 */
        CHECK_ERROR(_readMethod_indices_transfer_V5(c, &method->indices_transfer_V5))
        break;
    case 770: /* module 3 call 2 */
        CHECK_ERROR(_readMethod_indices_free_V5(c, &method->indices_free_V5))
        break;
    case 771: /* module 3 call 3 */
        CHECK_ERROR(_readMethod_indices_force_transfer_V5(c, &method->indices_force_transfer_V5))
        break;
    case 772: /* module 3 call 4 */
        CHECK_ERROR(_readMethod_indices_freeze_V5(c, &method->indices_freeze_V5))
        break;
    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V5(c, &method->balances_transfer_V5))
        break;
    case 1025: /* module 4 call 1 */
        CHECK_ERROR(_readMethod_balances_transfer_with_memo_V5(c, &method->balances_transfer_with_memo_V5))
        break;
    case 1026: /* module 4 call 2 */
        CHECK_ERROR(_readMethod_balances_deposit_block_reward_reserve_balance_V5(c, &method->balances_deposit_block_reward_reserve_balance_V5))
        break;
    case 1027: /* module 4 call 3 */
        CHECK_ERROR(_readMethod_balances_set_balance_V5(c, &method->balances_set_balance_V5))
        break;
    case 1028: /* module 4 call 4 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V5(c, &method->balances_force_transfer_V5))
        break;
    case 1029: /* module 4 call 5 */
        CHECK_ERROR(_readMethod_balances_burn_account_balance_V5(c, &method->balances_burn_account_balance_V5))
        break;
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_identity_register_did_V5(c, &method->identity_register_did_V5))
        break;
    case 1537: /* module 6 call 1 */
        CHECK_ERROR(_readMethod_identity_cdd_register_did_V5(c, &method->identity_cdd_register_did_V5))
        break;
    case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_identity_mock_cdd_register_did_V5(c, &method->identity_mock_cdd_register_did_V5))
        break;
    case 1539: /* module 6 call 3 */
        CHECK_ERROR(_readMethod_identity_invalidate_cdd_claims_V5(c, &method->identity_invalidate_cdd_claims_V5))
        break;
    case 1540: /* module 6 call 4 */
        CHECK_ERROR(_readMethod_identity_remove_secondary_keys_V5(c, &method->identity_remove_secondary_keys_V5))
        break;
    case 1541: /* module 6 call 5 */
        CHECK_ERROR(_readMethod_identity_accept_primary_key_V5(c, &method->identity_accept_primary_key_V5))
        break;
    case 1542: /* module 6 call 6 */
        CHECK_ERROR(_readMethod_identity_change_cdd_requirement_for_mk_rotation_V5(c, &method->identity_change_cdd_requirement_for_mk_rotation_V5))
        break;
    case 1543: /* module 6 call 7 */
        CHECK_ERROR(_readMethod_identity_join_identity_as_key_V5(c, &method->identity_join_identity_as_key_V5))
        break;
    case 1544: /* module 6 call 8 */
        CHECK_ERROR(_readMethod_identity_join_identity_as_identity_V5(c, &method->identity_join_identity_as_identity_V5))
        break;
    case 1545: /* module 6 call 9 */
        CHECK_ERROR(_readMethod_identity_leave_identity_as_key_V5(c, &method->identity_leave_identity_as_key_V5))
        break;
    case 1546: /* module 6 call 10 */
        CHECK_ERROR(_readMethod_identity_leave_identity_as_identity_V5(c, &method->identity_leave_identity_as_identity_V5))
        break;
    case 1547: /* module 6 call 11 */
        CHECK_ERROR(_readMethod_identity_add_claim_V5(c, &method->identity_add_claim_V5))
        break;
    case 1549: /* module 6 call 13 */
        CHECK_ERROR(_readMethod_identity_revoke_claim_V5(c, &method->identity_revoke_claim_V5))
        break;
    case 1550: /* module 6 call 14 */
        CHECK_ERROR(_readMethod_identity_set_permission_to_signer_V5(c, &method->identity_set_permission_to_signer_V5))
        break;
    case 1551: /* module 6 call 15 */
        CHECK_ERROR(_readMethod_identity_legacy_set_permission_to_signer_V5(c, &method->identity_legacy_set_permission_to_signer_V5))
        break;
    case 1552: /* module 6 call 16 */
        CHECK_ERROR(_readMethod_identity_freeze_secondary_keys_V5(c, &method->identity_freeze_secondary_keys_V5))
        break;
    case 1553: /* module 6 call 17 */
        CHECK_ERROR(_readMethod_identity_unfreeze_secondary_keys_V5(c, &method->identity_unfreeze_secondary_keys_V5))
        break;
    case 1554: /* module 6 call 18 */
        CHECK_ERROR(_readMethod_identity_get_my_did_V5(c, &method->identity_get_my_did_V5))
        break;
    case 1555: /* module 6 call 19 */
        CHECK_ERROR(_readMethod_identity_get_cdd_of_V5(c, &method->identity_get_cdd_of_V5))
        break;
    case 1556: /* module 6 call 20 */
        CHECK_ERROR(_readMethod_identity_add_authorization_V5(c, &method->identity_add_authorization_V5))
        break;
    case 1557: /* module 6 call 21 */
        CHECK_ERROR(_readMethod_identity_remove_authorization_V5(c, &method->identity_remove_authorization_V5))
        break;
    case 1558: /* module 6 call 22 */
        CHECK_ERROR(_readMethod_identity_accept_authorization_V5(c, &method->identity_accept_authorization_V5))
        break;
    case 1559: /* module 6 call 23 */
        CHECK_ERROR(_readMethod_identity_add_secondary_keys_with_authorization_V5(c, &method->identity_add_secondary_keys_with_authorization_V5))
        break;
    case 1560: /* module 6 call 24 */
        CHECK_ERROR(_readMethod_identity_revoke_offchain_authorization_V5(c, &method->identity_revoke_offchain_authorization_V5))
        break;
    case 1561: /* module 6 call 25 */
        CHECK_ERROR(_readMethod_identity_add_investor_uniqueness_claim_V5(c, &method->identity_add_investor_uniqueness_claim_V5))
        break;
    case 1562: /* module 6 call 26 */
        CHECK_ERROR(_readMethod_identity_gc_add_cdd_claim_V5(c, &method->identity_gc_add_cdd_claim_V5))
        break;
    case 1563: /* module 6 call 27 */
        CHECK_ERROR(_readMethod_identity_gc_revoke_cdd_claim_V5(c, &method->identity_gc_revoke_cdd_claim_V5))
        break;
    case 1792: /* module 7 call 0 */
        CHECK_ERROR(_readMethod_authorship_set_uncles_V5(c, &method->authorship_set_uncles_V5))
        break;
    case 2048: /* module 8 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V5(c, &method->staking_bond_V5))
        break;
    case 2049: /* module 8 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V5(c, &method->staking_bond_extra_V5))
        break;
    case 2050: /* module 8 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V5(c, &method->staking_unbond_V5))
        break;
    case 2051: /* module 8 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V5(c, &method->staking_withdraw_unbonded_V5))
        break;
    case 2052: /* module 8 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V5(c, &method->staking_validate_V5))
        break;
    case 2053: /* module 8 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V5(c, &method->staking_nominate_V5))
        break;
    case 2054: /* module 8 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V5(c, &method->staking_chill_V5))
        break;
    case 2055: /* module 8 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V5(c, &method->staking_set_payee_V5))
        break;
    case 2056: /* module 8 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V5(c, &method->staking_set_controller_V5))
        break;
    case 2057: /* module 8 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V5(c, &method->staking_set_validator_count_V5))
        break;
    case 2058: /* module 8 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V5(c, &method->staking_increase_validator_count_V5))
        break;
    case 2059: /* module 8 call 11 */
        CHECK_ERROR(_readMethod_staking_scale_validator_count_V5(c, &method->staking_scale_validator_count_V5))
        break;
    case 2060: /* module 8 call 12 */
        CHECK_ERROR(_readMethod_staking_add_permissioned_validator_V5(c, &method->staking_add_permissioned_validator_V5))
        break;
    case 2061: /* module 8 call 13 */
        CHECK_ERROR(_readMethod_staking_remove_permissioned_validator_V5(c, &method->staking_remove_permissioned_validator_V5))
        break;
    case 2062: /* module 8 call 14 */
        CHECK_ERROR(_readMethod_staking_validate_cdd_expiry_nominators_V5(c, &method->staking_validate_cdd_expiry_nominators_V5))
        break;
    case 2063: /* module 8 call 15 */
        CHECK_ERROR(_readMethod_staking_set_commission_cap_V5(c, &method->staking_set_commission_cap_V5))
        break;
    case 2064: /* module 8 call 16 */
        CHECK_ERROR(_readMethod_staking_set_min_bond_threshold_V5(c, &method->staking_set_min_bond_threshold_V5))
        break;
    case 2065: /* module 8 call 17 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V5(c, &method->staking_force_no_eras_V5))
        break;
    case 2066: /* module 8 call 18 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V5(c, &method->staking_force_new_era_V5))
        break;
    case 2067: /* module 8 call 19 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V5(c, &method->staking_set_invulnerables_V5))
        break;
    case 2068: /* module 8 call 20 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V5(c, &method->staking_force_unstake_V5))
        break;
    case 2069: /* module 8 call 21 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V5(c, &method->staking_force_new_era_always_V5))
        break;
    case 2070: /* module 8 call 22 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V5(c, &method->staking_cancel_deferred_slash_V5))
        break;
    case 2071: /* module 8 call 23 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V5(c, &method->staking_payout_stakers_V5))
        break;
    case 2072: /* module 8 call 24 */
        CHECK_ERROR(_readMethod_staking_rebond_V5(c, &method->staking_rebond_V5))
        break;
    case 2073: /* module 8 call 25 */
        CHECK_ERROR(_readMethod_staking_set_history_depth_V5(c, &method->staking_set_history_depth_V5))
        break;
    case 2074: /* module 8 call 26 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V5(c, &method->staking_reap_stash_V5))
        break;
    case 2075: /* module 8 call 27 */
        CHECK_ERROR(_readMethod_staking_submit_election_solution_V5(c, &method->staking_submit_election_solution_V5))
        break;
    case 2076: /* module 8 call 28 */
        CHECK_ERROR(_readMethod_staking_submit_election_solution_unsigned_V5(c, &method->staking_submit_election_solution_unsigned_V5))
        break;
    case 2077: /* module 8 call 29 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_by_system_V5(c, &method->staking_payout_stakers_by_system_V5))
        break;
    case 2078: /* module 8 call 30 */
        CHECK_ERROR(_readMethod_staking_change_slashing_allowed_for_V5(c, &method->staking_change_slashing_allowed_for_V5))
        break;
    case 2079: /* module 8 call 31 */
        CHECK_ERROR(_readMethod_staking_update_permissioned_validator_intended_count_V5(c, &method->staking_update_permissioned_validator_intended_count_V5))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V5(c, &method->session_set_keys_V5))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V5(c, &method->session_purge_keys_V5))
        break;
    case 2816: /* module 11 call 0 */
        CHECK_ERROR(_readMethod_finalitytracker_final_hint_V5(c, &method->finalitytracker_final_hint_V5))
        break;
    case 3072: /* module 12 call 0 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_V5(c, &method->grandpa_report_equivocation_V5))
        break;
    case 3073: /* module 12 call 1 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_unsigned_V5(c, &method->grandpa_report_equivocation_unsigned_V5))
        break;
    case 3074: /* module 12 call 2 */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V5(c, &method->grandpa_note_stalled_V5))
        break;
    case 3328: /* module 13 call 0 */
        CHECK_ERROR(_readMethod_imonline_heartbeat_V5(c, &method->imonline_heartbeat_V5))
        break;
    case 3329: /* module 13 call 1 */
        CHECK_ERROR(_readMethod_imonline_set_slashing_params_V5(c, &method->imonline_set_slashing_params_V5))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_sudo_set_key_V5(c, &method->sudo_set_key_V5))
        break;
    case 4608: /* module 18 call 0 */
        CHECK_ERROR(_readMethod_multisig_create_multisig_V5(c, &method->multisig_create_multisig_V5))
        break;
    case 4613: /* module 18 call 5 */
        CHECK_ERROR(_readMethod_multisig_approve_as_identity_V5(c, &method->multisig_approve_as_identity_V5))
        break;
    case 4614: /* module 18 call 6 */
        CHECK_ERROR(_readMethod_multisig_approve_as_key_V5(c, &method->multisig_approve_as_key_V5))
        break;
    case 4615: /* module 18 call 7 */
        CHECK_ERROR(_readMethod_multisig_reject_as_identity_V5(c, &method->multisig_reject_as_identity_V5))
        break;
    case 4616: /* module 18 call 8 */
        CHECK_ERROR(_readMethod_multisig_reject_as_key_V5(c, &method->multisig_reject_as_key_V5))
        break;
    case 4617: /* module 18 call 9 */
        CHECK_ERROR(_readMethod_multisig_accept_multisig_signer_as_identity_V5(c, &method->multisig_accept_multisig_signer_as_identity_V5))
        break;
    case 4618: /* module 18 call 10 */
        CHECK_ERROR(_readMethod_multisig_accept_multisig_signer_as_key_V5(c, &method->multisig_accept_multisig_signer_as_key_V5))
        break;
    case 4619: /* module 18 call 11 */
        CHECK_ERROR(_readMethod_multisig_add_multisig_signer_V5(c, &method->multisig_add_multisig_signer_V5))
        break;
    case 4620: /* module 18 call 12 */
        CHECK_ERROR(_readMethod_multisig_remove_multisig_signer_V5(c, &method->multisig_remove_multisig_signer_V5))
        break;
    case 4621: /* module 18 call 13 */
        CHECK_ERROR(_readMethod_multisig_add_multisig_signers_via_creator_V5(c, &method->multisig_add_multisig_signers_via_creator_V5))
        break;
    case 4622: /* module 18 call 14 */
        CHECK_ERROR(_readMethod_multisig_remove_multisig_signers_via_creator_V5(c, &method->multisig_remove_multisig_signers_via_creator_V5))
        break;
    case 4623: /* module 18 call 15 */
        CHECK_ERROR(_readMethod_multisig_change_sigs_required_V5(c, &method->multisig_change_sigs_required_V5))
        break;
    case 4624: /* module 18 call 16 */
        CHECK_ERROR(_readMethod_multisig_make_multisig_signer_V5(c, &method->multisig_make_multisig_signer_V5))
        break;
    case 4625: /* module 18 call 17 */
        CHECK_ERROR(_readMethod_multisig_make_multisig_primary_V5(c, &method->multisig_make_multisig_primary_V5))
        break;
    case 4626: /* module 18 call 18 */
        CHECK_ERROR(_readMethod_multisig_execute_scheduled_proposal_V5(c, &method->multisig_execute_scheduled_proposal_V5))
        break;
    case 5120: /* module 20 call 0 */
        CHECK_ERROR(_readMethod_contracts_update_schedule_V5(c, &method->contracts_update_schedule_V5))
        break;
    case 5121: /* module 20 call 1 */
        CHECK_ERROR(_readMethod_contracts_put_code_V5(c, &method->contracts_put_code_V5))
        break;
    case 5122: /* module 20 call 2 */
        CHECK_ERROR(_readMethod_contracts_call_V5(c, &method->contracts_call_V5))
        break;
    case 5123: /* module 20 call 3 */
        CHECK_ERROR(_readMethod_contracts_instantiate_V5(c, &method->contracts_instantiate_V5))
        break;
    case 5124: /* module 20 call 4 */
        CHECK_ERROR(_readMethod_contracts_freeze_instantiation_V5(c, &method->contracts_freeze_instantiation_V5))
        break;
    case 5125: /* module 20 call 5 */
        CHECK_ERROR(_readMethod_contracts_unfreeze_instantiation_V5(c, &method->contracts_unfreeze_instantiation_V5))
        break;
    case 5126: /* module 20 call 6 */
        CHECK_ERROR(_readMethod_contracts_transfer_template_ownership_V5(c, &method->contracts_transfer_template_ownership_V5))
        break;
    case 5127: /* module 20 call 7 */
        CHECK_ERROR(_readMethod_contracts_change_template_fees_V5(c, &method->contracts_change_template_fees_V5))
        break;
    case 5128: /* module 20 call 8 */
        CHECK_ERROR(_readMethod_contracts_change_template_meta_url_V5(c, &method->contracts_change_template_meta_url_V5))
        break;
    case 5376: /* module 21 call 0 */
        CHECK_ERROR(_readMethod_treasury_disbursement_V5(c, &method->treasury_disbursement_V5))
        break;
    case 5377: /* module 21 call 1 */
        CHECK_ERROR(_readMethod_treasury_reimbursement_V5(c, &method->treasury_reimbursement_V5))
        break;
    case 5632: /* module 22 call 0 */
        CHECK_ERROR(_readMethod_polymeshcommittee_set_vote_threshold_V5(c, &method->polymeshcommittee_set_vote_threshold_V5))
        break;
    case 5633: /* module 22 call 1 */
        CHECK_ERROR(_readMethod_polymeshcommittee_set_release_coordinator_V5(c, &method->polymeshcommittee_set_release_coordinator_V5))
        break;
    case 5634: /* module 22 call 2 */
        CHECK_ERROR(_readMethod_polymeshcommittee_set_expires_after_V5(c, &method->polymeshcommittee_set_expires_after_V5))
        break;
    case 5636: /* module 22 call 4 */
        CHECK_ERROR(_readMethod_polymeshcommittee_vote_V5(c, &method->polymeshcommittee_vote_V5))
        break;
    case 5888: /* module 23 call 0 */
        CHECK_ERROR(_readMethod_committeemembership_set_active_members_limit_V5(c, &method->committeemembership_set_active_members_limit_V5))
        break;
    case 5889: /* module 23 call 1 */
        CHECK_ERROR(_readMethod_committeemembership_disable_member_V5(c, &method->committeemembership_disable_member_V5))
        break;
    case 5890: /* module 23 call 2 */
        CHECK_ERROR(_readMethod_committeemembership_add_member_V5(c, &method->committeemembership_add_member_V5))
        break;
    case 5891: /* module 23 call 3 */
        CHECK_ERROR(_readMethod_committeemembership_remove_member_V5(c, &method->committeemembership_remove_member_V5))
        break;
    case 5892: /* module 23 call 4 */
        CHECK_ERROR(_readMethod_committeemembership_swap_member_V5(c, &method->committeemembership_swap_member_V5))
        break;
    case 5893: /* module 23 call 5 */
        CHECK_ERROR(_readMethod_committeemembership_reset_members_V5(c, &method->committeemembership_reset_members_V5))
        break;
    case 5894: /* module 23 call 6 */
        CHECK_ERROR(_readMethod_committeemembership_abdicate_membership_V5(c, &method->committeemembership_abdicate_membership_V5))
        break;
    case 6144: /* module 24 call 0 */
        CHECK_ERROR(_readMethod_pips_set_prune_historical_pips_V5(c, &method->pips_set_prune_historical_pips_V5))
        break;
    case 6145: /* module 24 call 1 */
        CHECK_ERROR(_readMethod_pips_set_min_proposal_deposit_V5(c, &method->pips_set_min_proposal_deposit_V5))
        break;
    case 6146: /* module 24 call 2 */
        CHECK_ERROR(_readMethod_pips_set_default_enactment_period_V5(c, &method->pips_set_default_enactment_period_V5))
        break;
    case 6147: /* module 24 call 3 */
        CHECK_ERROR(_readMethod_pips_set_pending_pip_expiry_V5(c, &method->pips_set_pending_pip_expiry_V5))
        break;
    case 6148: /* module 24 call 4 */
        CHECK_ERROR(_readMethod_pips_set_max_pip_skip_count_V5(c, &method->pips_set_max_pip_skip_count_V5))
        break;
    case 6149: /* module 24 call 5 */
        CHECK_ERROR(_readMethod_pips_set_active_pip_limit_V5(c, &method->pips_set_active_pip_limit_V5))
        break;
    case 6151: /* module 24 call 7 */
        CHECK_ERROR(_readMethod_pips_vote_V5(c, &method->pips_vote_V5))
        break;
    case 6152: /* module 24 call 8 */
        CHECK_ERROR(_readMethod_pips_approve_committee_proposal_V5(c, &method->pips_approve_committee_proposal_V5))
        break;
    case 6153: /* module 24 call 9 */
        CHECK_ERROR(_readMethod_pips_reject_proposal_V5(c, &method->pips_reject_proposal_V5))
        break;
    case 6154: /* module 24 call 10 */
        CHECK_ERROR(_readMethod_pips_prune_proposal_V5(c, &method->pips_prune_proposal_V5))
        break;
    case 6155: /* module 24 call 11 */
        CHECK_ERROR(_readMethod_pips_reschedule_execution_V5(c, &method->pips_reschedule_execution_V5))
        break;
    case 6156: /* module 24 call 12 */
        CHECK_ERROR(_readMethod_pips_clear_snapshot_V5(c, &method->pips_clear_snapshot_V5))
        break;
    case 6157: /* module 24 call 13 */
        CHECK_ERROR(_readMethod_pips_snapshot_V5(c, &method->pips_snapshot_V5))
        break;
    case 6158: /* module 24 call 14 */
        CHECK_ERROR(_readMethod_pips_enact_snapshot_results_V5(c, &method->pips_enact_snapshot_results_V5))
        break;
    case 6159: /* module 24 call 15 */
        CHECK_ERROR(_readMethod_pips_execute_scheduled_pip_V5(c, &method->pips_execute_scheduled_pip_V5))
        break;
    case 6160: /* module 24 call 16 */
        CHECK_ERROR(_readMethod_pips_expire_scheduled_pip_V5(c, &method->pips_expire_scheduled_pip_V5))
        break;
    case 6400: /* module 25 call 0 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_vote_threshold_V5(c, &method->technicalcommittee_set_vote_threshold_V5))
        break;
    case 6401: /* module 25 call 1 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_release_coordinator_V5(c, &method->technicalcommittee_set_release_coordinator_V5))
        break;
    case 6402: /* module 25 call 2 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_expires_after_V5(c, &method->technicalcommittee_set_expires_after_V5))
        break;
    case 6404: /* module 25 call 4 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_V5(c, &method->technicalcommittee_vote_V5))
        break;
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_set_active_members_limit_V5(c, &method->technicalcommitteemembership_set_active_members_limit_V5))
        break;
    case 6657: /* module 26 call 1 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_disable_member_V5(c, &method->technicalcommitteemembership_disable_member_V5))
        break;
    case 6658: /* module 26 call 2 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_add_member_V5(c, &method->technicalcommitteemembership_add_member_V5))
        break;
    case 6659: /* module 26 call 3 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_remove_member_V5(c, &method->technicalcommitteemembership_remove_member_V5))
        break;
    case 6660: /* module 26 call 4 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_swap_member_V5(c, &method->technicalcommitteemembership_swap_member_V5))
        break;
    case 6661: /* module 26 call 5 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_reset_members_V5(c, &method->technicalcommitteemembership_reset_members_V5))
        break;
    case 6662: /* module 26 call 6 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_abdicate_membership_V5(c, &method->technicalcommitteemembership_abdicate_membership_V5))
        break;
    case 6912: /* module 27 call 0 */
        CHECK_ERROR(_readMethod_upgradecommittee_set_vote_threshold_V5(c, &method->upgradecommittee_set_vote_threshold_V5))
        break;
    case 6913: /* module 27 call 1 */
        CHECK_ERROR(_readMethod_upgradecommittee_set_release_coordinator_V5(c, &method->upgradecommittee_set_release_coordinator_V5))
        break;
    case 6914: /* module 27 call 2 */
        CHECK_ERROR(_readMethod_upgradecommittee_set_expires_after_V5(c, &method->upgradecommittee_set_expires_after_V5))
        break;
    case 6916: /* module 27 call 4 */
        CHECK_ERROR(_readMethod_upgradecommittee_vote_V5(c, &method->upgradecommittee_vote_V5))
        break;
    case 7168: /* module 28 call 0 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_set_active_members_limit_V5(c, &method->upgradecommitteemembership_set_active_members_limit_V5))
        break;
    case 7169: /* module 28 call 1 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_disable_member_V5(c, &method->upgradecommitteemembership_disable_member_V5))
        break;
    case 7170: /* module 28 call 2 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_add_member_V5(c, &method->upgradecommitteemembership_add_member_V5))
        break;
    case 7171: /* module 28 call 3 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_remove_member_V5(c, &method->upgradecommitteemembership_remove_member_V5))
        break;
    case 7172: /* module 28 call 4 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_swap_member_V5(c, &method->upgradecommitteemembership_swap_member_V5))
        break;
    case 7173: /* module 28 call 5 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_reset_members_V5(c, &method->upgradecommitteemembership_reset_members_V5))
        break;
    case 7174: /* module 28 call 6 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_abdicate_membership_V5(c, &method->upgradecommitteemembership_abdicate_membership_V5))
        break;
    case 7424: /* module 29 call 0 */
        CHECK_ERROR(_readMethod_asset_register_ticker_V5(c, &method->asset_register_ticker_V5))
        break;
    case 7425: /* module 29 call 1 */
        CHECK_ERROR(_readMethod_asset_accept_ticker_transfer_V5(c, &method->asset_accept_ticker_transfer_V5))
        break;
    case 7426: /* module 29 call 2 */
        CHECK_ERROR(_readMethod_asset_accept_primary_issuance_agent_transfer_V5(c, &method->asset_accept_primary_issuance_agent_transfer_V5))
        break;
    case 7427: /* module 29 call 3 */
        CHECK_ERROR(_readMethod_asset_accept_asset_ownership_transfer_V5(c, &method->asset_accept_asset_ownership_transfer_V5))
        break;
    case 7428: /* module 29 call 4 */
        CHECK_ERROR(_readMethod_asset_create_asset_V5(c, &method->asset_create_asset_V5))
        break;
    case 7429: /* module 29 call 5 */
        CHECK_ERROR(_readMethod_asset_freeze_V5(c, &method->asset_freeze_V5))
        break;
    case 7430: /* module 29 call 6 */
        CHECK_ERROR(_readMethod_asset_unfreeze_V5(c, &method->asset_unfreeze_V5))
        break;
    case 7431: /* module 29 call 7 */
        CHECK_ERROR(_readMethod_asset_rename_asset_V5(c, &method->asset_rename_asset_V5))
        break;
    case 7432: /* module 29 call 8 */
        CHECK_ERROR(_readMethod_asset_issue_V5(c, &method->asset_issue_V5))
        break;
    case 7433: /* module 29 call 9 */
        CHECK_ERROR(_readMethod_asset_redeem_V5(c, &method->asset_redeem_V5))
        break;
    case 7434: /* module 29 call 10 */
        CHECK_ERROR(_readMethod_asset_make_divisible_V5(c, &method->asset_make_divisible_V5))
        break;
    case 7435: /* module 29 call 11 */
        CHECK_ERROR(_readMethod_asset_add_documents_V5(c, &method->asset_add_documents_V5))
        break;
    case 7436: /* module 29 call 12 */
        CHECK_ERROR(_readMethod_asset_remove_documents_V5(c, &method->asset_remove_documents_V5))
        break;
    case 7437: /* module 29 call 13 */
        CHECK_ERROR(_readMethod_asset_set_funding_round_V5(c, &method->asset_set_funding_round_V5))
        break;
    case 7438: /* module 29 call 14 */
        CHECK_ERROR(_readMethod_asset_update_identifiers_V5(c, &method->asset_update_identifiers_V5))
        break;
    case 7439: /* module 29 call 15 */
        CHECK_ERROR(_readMethod_asset_add_extension_V5(c, &method->asset_add_extension_V5))
        break;
    case 7440: /* module 29 call 16 */
        CHECK_ERROR(_readMethod_asset_archive_extension_V5(c, &method->asset_archive_extension_V5))
        break;
    case 7441: /* module 29 call 17 */
        CHECK_ERROR(_readMethod_asset_unarchive_extension_V5(c, &method->asset_unarchive_extension_V5))
        break;
    case 7442: /* module 29 call 18 */
        CHECK_ERROR(_readMethod_asset_remove_primary_issuance_agent_V5(c, &method->asset_remove_primary_issuance_agent_V5))
        break;
    case 7443: /* module 29 call 19 */
        CHECK_ERROR(_readMethod_asset_remove_smart_extension_V5(c, &method->asset_remove_smart_extension_V5))
        break;
    case 7444: /* module 29 call 20 */
        CHECK_ERROR(_readMethod_asset_claim_classic_ticker_V5(c, &method->asset_claim_classic_ticker_V5))
        break;
    case 7445: /* module 29 call 21 */
        CHECK_ERROR(_readMethod_asset_reserve_classic_ticker_V5(c, &method->asset_reserve_classic_ticker_V5))
        break;
    case 7936: /* module 31 call 0 */
        CHECK_ERROR(_readMethod_bridge_change_controller_V5(c, &method->bridge_change_controller_V5))
        break;
    case 7937: /* module 31 call 1 */
        CHECK_ERROR(_readMethod_bridge_change_admin_V5(c, &method->bridge_change_admin_V5))
        break;
    case 7938: /* module 31 call 2 */
        CHECK_ERROR(_readMethod_bridge_change_timelock_V5(c, &method->bridge_change_timelock_V5))
        break;
    case 7939: /* module 31 call 3 */
        CHECK_ERROR(_readMethod_bridge_freeze_V5(c, &method->bridge_freeze_V5))
        break;
    case 7940: /* module 31 call 4 */
        CHECK_ERROR(_readMethod_bridge_unfreeze_V5(c, &method->bridge_unfreeze_V5))
        break;
    case 7941: /* module 31 call 5 */
        CHECK_ERROR(_readMethod_bridge_change_bridge_limit_V5(c, &method->bridge_change_bridge_limit_V5))
        break;
    case 7942: /* module 31 call 6 */
        CHECK_ERROR(_readMethod_bridge_change_bridge_exempted_V5(c, &method->bridge_change_bridge_exempted_V5))
        break;
    case 7943: /* module 31 call 7 */
        CHECK_ERROR(_readMethod_bridge_force_handle_bridge_tx_V5(c, &method->bridge_force_handle_bridge_tx_V5))
        break;
    case 7944: /* module 31 call 8 */
        CHECK_ERROR(_readMethod_bridge_batch_propose_bridge_tx_V5(c, &method->bridge_batch_propose_bridge_tx_V5))
        break;
    case 7945: /* module 31 call 9 */
        CHECK_ERROR(_readMethod_bridge_propose_bridge_tx_V5(c, &method->bridge_propose_bridge_tx_V5))
        break;
    case 7946: /* module 31 call 10 */
        CHECK_ERROR(_readMethod_bridge_handle_bridge_tx_V5(c, &method->bridge_handle_bridge_tx_V5))
        break;
    case 7947: /* module 31 call 11 */
        CHECK_ERROR(_readMethod_bridge_freeze_txs_V5(c, &method->bridge_freeze_txs_V5))
        break;
    case 7948: /* module 31 call 12 */
        CHECK_ERROR(_readMethod_bridge_unfreeze_txs_V5(c, &method->bridge_unfreeze_txs_V5))
        break;
    case 7949: /* module 31 call 13 */
        CHECK_ERROR(_readMethod_bridge_handle_scheduled_bridge_tx_V5(c, &method->bridge_handle_scheduled_bridge_tx_V5))
        break;
    case 8192: /* module 32 call 0 */
        CHECK_ERROR(_readMethod_compliancemanager_add_compliance_requirement_V5(c, &method->compliancemanager_add_compliance_requirement_V5))
        break;
    case 8193: /* module 32 call 1 */
        CHECK_ERROR(_readMethod_compliancemanager_remove_compliance_requirement_V5(c, &method->compliancemanager_remove_compliance_requirement_V5))
        break;
    case 8194: /* module 32 call 2 */
        CHECK_ERROR(_readMethod_compliancemanager_replace_asset_compliance_V5(c, &method->compliancemanager_replace_asset_compliance_V5))
        break;
    case 8195: /* module 32 call 3 */
        CHECK_ERROR(_readMethod_compliancemanager_reset_asset_compliance_V5(c, &method->compliancemanager_reset_asset_compliance_V5))
        break;
    case 8196: /* module 32 call 4 */
        CHECK_ERROR(_readMethod_compliancemanager_pause_asset_compliance_V5(c, &method->compliancemanager_pause_asset_compliance_V5))
        break;
    case 8197: /* module 32 call 5 */
        CHECK_ERROR(_readMethod_compliancemanager_resume_asset_compliance_V5(c, &method->compliancemanager_resume_asset_compliance_V5))
        break;
    case 8198: /* module 32 call 6 */
        CHECK_ERROR(_readMethod_compliancemanager_add_default_trusted_claim_issuer_V5(c, &method->compliancemanager_add_default_trusted_claim_issuer_V5))
        break;
    case 8199: /* module 32 call 7 */
        CHECK_ERROR(_readMethod_compliancemanager_remove_default_trusted_claim_issuer_V5(c, &method->compliancemanager_remove_default_trusted_claim_issuer_V5))
        break;
    case 8200: /* module 32 call 8 */
        CHECK_ERROR(_readMethod_compliancemanager_change_compliance_requirement_V5(c, &method->compliancemanager_change_compliance_requirement_V5))
        break;
    case 9216: /* module 36 call 0 */
        CHECK_ERROR(_readMethod_settlement_create_venue_V5(c, &method->settlement_create_venue_V5))
        break;
    case 9217: /* module 36 call 1 */
        CHECK_ERROR(_readMethod_settlement_update_venue_V5(c, &method->settlement_update_venue_V5))
        break;
    case 9218: /* module 36 call 2 */
        CHECK_ERROR(_readMethod_settlement_add_instruction_V5(c, &method->settlement_add_instruction_V5))
        break;
    case 9219: /* module 36 call 3 */
        CHECK_ERROR(_readMethod_settlement_add_and_affirm_instruction_V5(c, &method->settlement_add_and_affirm_instruction_V5))
        break;
    case 9220: /* module 36 call 4 */
        CHECK_ERROR(_readMethod_settlement_affirm_instruction_V5(c, &method->settlement_affirm_instruction_V5))
        break;
    case 9221: /* module 36 call 5 */
        CHECK_ERROR(_readMethod_settlement_withdraw_affirmation_V5(c, &method->settlement_withdraw_affirmation_V5))
        break;
    case 9222: /* module 36 call 6 */
        CHECK_ERROR(_readMethod_settlement_reject_instruction_V5(c, &method->settlement_reject_instruction_V5))
        break;
    case 9223: /* module 36 call 7 */
        CHECK_ERROR(_readMethod_settlement_affirm_with_receipts_V5(c, &method->settlement_affirm_with_receipts_V5))
        break;
    case 9224: /* module 36 call 8 */
        CHECK_ERROR(_readMethod_settlement_claim_receipt_V5(c, &method->settlement_claim_receipt_V5))
        break;
    case 9225: /* module 36 call 9 */
        CHECK_ERROR(_readMethod_settlement_unclaim_receipt_V5(c, &method->settlement_unclaim_receipt_V5))
        break;
    case 9226: /* module 36 call 10 */
        CHECK_ERROR(_readMethod_settlement_set_venue_filtering_V5(c, &method->settlement_set_venue_filtering_V5))
        break;
    case 9227: /* module 36 call 11 */
        CHECK_ERROR(_readMethod_settlement_allow_venues_V5(c, &method->settlement_allow_venues_V5))
        break;
    case 9228: /* module 36 call 12 */
        CHECK_ERROR(_readMethod_settlement_disallow_venues_V5(c, &method->settlement_disallow_venues_V5))
        break;
    case 9229: /* module 36 call 13 */
        CHECK_ERROR(_readMethod_settlement_execute_scheduled_instruction_V5(c, &method->settlement_execute_scheduled_instruction_V5))
        break;
    case 9472: /* module 37 call 0 */
        CHECK_ERROR(_readMethod_sto_create_fundraiser_V5(c, &method->sto_create_fundraiser_V5))
        break;
    case 9473: /* module 37 call 1 */
        CHECK_ERROR(_readMethod_sto_invest_V5(c, &method->sto_invest_V5))
        break;
    case 9474: /* module 37 call 2 */
        CHECK_ERROR(_readMethod_sto_freeze_fundraiser_V5(c, &method->sto_freeze_fundraiser_V5))
        break;
    case 9475: /* module 37 call 3 */
        CHECK_ERROR(_readMethod_sto_unfreeze_fundraiser_V5(c, &method->sto_unfreeze_fundraiser_V5))
        break;
    case 9476: /* module 37 call 4 */
        CHECK_ERROR(_readMethod_sto_modify_fundraiser_window_V5(c, &method->sto_modify_fundraiser_window_V5))
        break;
    case 9477: /* module 37 call 5 */
        CHECK_ERROR(_readMethod_sto_stop_V5(c, &method->sto_stop_V5))
        break;
    case 9728: /* module 38 call 0 */
        CHECK_ERROR(_readMethod_cddserviceproviders_set_active_members_limit_V5(c, &method->cddserviceproviders_set_active_members_limit_V5))
        break;
    case 9729: /* module 38 call 1 */
        CHECK_ERROR(_readMethod_cddserviceproviders_disable_member_V5(c, &method->cddserviceproviders_disable_member_V5))
        break;
    case 9730: /* module 38 call 2 */
        CHECK_ERROR(_readMethod_cddserviceproviders_add_member_V5(c, &method->cddserviceproviders_add_member_V5))
        break;
    case 9731: /* module 38 call 3 */
        CHECK_ERROR(_readMethod_cddserviceproviders_remove_member_V5(c, &method->cddserviceproviders_remove_member_V5))
        break;
    case 9732: /* module 38 call 4 */
        CHECK_ERROR(_readMethod_cddserviceproviders_swap_member_V5(c, &method->cddserviceproviders_swap_member_V5))
        break;
    case 9733: /* module 38 call 5 */
        CHECK_ERROR(_readMethod_cddserviceproviders_reset_members_V5(c, &method->cddserviceproviders_reset_members_V5))
        break;
    case 9734: /* module 38 call 6 */
        CHECK_ERROR(_readMethod_cddserviceproviders_abdicate_membership_V5(c, &method->cddserviceproviders_abdicate_membership_V5))
        break;
    case 9984: /* module 39 call 0 */
        CHECK_ERROR(_readMethod_statistics_add_transfer_manager_V5(c, &method->statistics_add_transfer_manager_V5))
        break;
    case 9985: /* module 39 call 1 */
        CHECK_ERROR(_readMethod_statistics_remove_transfer_manager_V5(c, &method->statistics_remove_transfer_manager_V5))
        break;
    case 9986: /* module 39 call 2 */
        CHECK_ERROR(_readMethod_statistics_add_exempted_entities_V5(c, &method->statistics_add_exempted_entities_V5))
        break;
    case 9987: /* module 39 call 3 */
        CHECK_ERROR(_readMethod_statistics_remove_exempted_entities_V5(c, &method->statistics_remove_exempted_entities_V5))
        break;
    case 10240: /* module 40 call 0 */
        CHECK_ERROR(_readMethod_protocolfee_change_coefficient_V5(c, &method->protocolfee_change_coefficient_V5))
        break;
    case 10241: /* module 40 call 1 */
        CHECK_ERROR(_readMethod_protocolfee_change_base_fee_V5(c, &method->protocolfee_change_base_fee_V5))
        break;
    case 10496: /* module 41 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V5(c, &method->utility_batch_V5))
        break;
    case 10497: /* module 41 call 1 */
        CHECK_ERROR(_readMethod_utility_batch_atomic_V5(c, &method->utility_batch_atomic_V5))
        break;
    case 10498: /* module 41 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_optimistic_V5(c, &method->utility_batch_optimistic_V5))
        break;
    case 10499: /* module 41 call 3 */
        CHECK_ERROR(_readMethod_utility_relay_tx_V5(c, &method->utility_relay_tx_V5))
        break;
    case 10752: /* module 42 call 0 */
        CHECK_ERROR(_readMethod_portfolio_create_portfolio_V5(c, &method->portfolio_create_portfolio_V5))
        break;
    case 10753: /* module 42 call 1 */
        CHECK_ERROR(_readMethod_portfolio_delete_portfolio_V5(c, &method->portfolio_delete_portfolio_V5))
        break;
    case 10754: /* module 42 call 2 */
        CHECK_ERROR(_readMethod_portfolio_move_portfolio_funds_V5(c, &method->portfolio_move_portfolio_funds_V5))
        break;
    case 10755: /* module 42 call 3 */
        CHECK_ERROR(_readMethod_portfolio_rename_portfolio_V5(c, &method->portfolio_rename_portfolio_V5))
        break;
    case 11008: /* module 43 call 0 */
        CHECK_ERROR(_readMethod_confidential_add_range_proof_V5(c, &method->confidential_add_range_proof_V5))
        break;
    case 11009: /* module 43 call 1 */
        CHECK_ERROR(_readMethod_confidential_add_verify_range_proof_V5(c, &method->confidential_add_verify_range_proof_V5))
        break;
    case 11521: /* module 45 call 1 */
        CHECK_ERROR(_readMethod_scheduler_cancel_V5(c, &method->scheduler_cancel_V5))
        break;
    case 11523: /* module 45 call 3 */
        CHECK_ERROR(_readMethod_scheduler_cancel_named_V5(c, &method->scheduler_cancel_named_V5))
        break;
    case 11776: /* module 46 call 0 */
        CHECK_ERROR(_readMethod_corporateaction_set_max_details_length_V5(c, &method->corporateaction_set_max_details_length_V5))
        break;
    case 11777: /* module 46 call 1 */
        CHECK_ERROR(_readMethod_corporateaction_reset_caa_V5(c, &method->corporateaction_reset_caa_V5))
        break;
    case 11778: /* module 46 call 2 */
        CHECK_ERROR(_readMethod_corporateaction_set_default_targets_V5(c, &method->corporateaction_set_default_targets_V5))
        break;
    case 11779: /* module 46 call 3 */
        CHECK_ERROR(_readMethod_corporateaction_set_default_withholding_tax_V5(c, &method->corporateaction_set_default_withholding_tax_V5))
        break;
    case 11780: /* module 46 call 4 */
        CHECK_ERROR(_readMethod_corporateaction_set_did_withholding_tax_V5(c, &method->corporateaction_set_did_withholding_tax_V5))
        break;
    case 11781: /* module 46 call 5 */
        CHECK_ERROR(_readMethod_corporateaction_initiate_corporate_action_V5(c, &method->corporateaction_initiate_corporate_action_V5))
        break;
    case 11782: /* module 46 call 6 */
        CHECK_ERROR(_readMethod_corporateaction_link_ca_doc_V5(c, &method->corporateaction_link_ca_doc_V5))
        break;
    case 11783: /* module 46 call 7 */
        CHECK_ERROR(_readMethod_corporateaction_remove_ca_V5(c, &method->corporateaction_remove_ca_V5))
        break;
    case 11784: /* module 46 call 8 */
        CHECK_ERROR(_readMethod_corporateaction_change_record_date_V5(c, &method->corporateaction_change_record_date_V5))
        break;
    case 12032: /* module 47 call 0 */
        CHECK_ERROR(_readMethod_corporateballot_attach_ballot_V5(c, &method->corporateballot_attach_ballot_V5))
        break;
    case 12033: /* module 47 call 1 */
        CHECK_ERROR(_readMethod_corporateballot_vote_V5(c, &method->corporateballot_vote_V5))
        break;
    case 12034: /* module 47 call 2 */
        CHECK_ERROR(_readMethod_corporateballot_change_end_V5(c, &method->corporateballot_change_end_V5))
        break;
    case 12035: /* module 47 call 3 */
        CHECK_ERROR(_readMethod_corporateballot_change_meta_V5(c, &method->corporateballot_change_meta_V5))
        break;
    case 12036: /* module 47 call 4 */
        CHECK_ERROR(_readMethod_corporateballot_change_rcv_V5(c, &method->corporateballot_change_rcv_V5))
        break;
    case 12037: /* module 47 call 5 */
        CHECK_ERROR(_readMethod_corporateballot_remove_ballot_V5(c, &method->corporateballot_remove_ballot_V5))
        break;
    case 12288: /* module 48 call 0 */
        CHECK_ERROR(_readMethod_capitaldistribution_distribute_V5(c, &method->capitaldistribution_distribute_V5))
        break;
    case 12289: /* module 48 call 1 */
        CHECK_ERROR(_readMethod_capitaldistribution_claim_V5(c, &method->capitaldistribution_claim_V5))
        break;
    case 12290: /* module 48 call 2 */
        CHECK_ERROR(_readMethod_capitaldistribution_push_benefit_V5(c, &method->capitaldistribution_push_benefit_V5))
        break;
    case 12291: /* module 48 call 3 */
        CHECK_ERROR(_readMethod_capitaldistribution_reclaim_V5(c, &method->capitaldistribution_reclaim_V5))
        break;
    case 12292: /* module 48 call 4 */
        CHECK_ERROR(_readMethod_capitaldistribution_remove_distribution_V5(c, &method->capitaldistribution_remove_distribution_V5))
        break;
    case 12544: /* module 49 call 0 */
        CHECK_ERROR(_readMethod_checkpoint_create_checkpoint_V5(c, &method->checkpoint_create_checkpoint_V5))
        break;
    case 12545: /* module 49 call 1 */
        CHECK_ERROR(_readMethod_checkpoint_set_schedules_max_complexity_V5(c, &method->checkpoint_set_schedules_max_complexity_V5))
        break;
    case 12546: /* module 49 call 2 */
        CHECK_ERROR(_readMethod_checkpoint_create_schedule_V5(c, &method->checkpoint_create_schedule_V5))
        break;
    case 12547: /* module 49 call 3 */
        CHECK_ERROR(_readMethod_checkpoint_remove_schedule_V5(c, &method->checkpoint_remove_schedule_V5))
        break;
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

parser_error_t _readMethod_V5(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V5_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V5(c, &method->basic.system_fill_block_V5))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V5(c, &method->basic.system_remark_V5))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V5(c, &method->basic.system_set_heap_pages_V5))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V5(c, &method->basic.system_set_code_V5))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V5(c, &method->basic.system_set_code_without_checks_V5))
        break;
    case 5: /* module 0 call 5 */
        CHECK_ERROR(_readMethod_system_set_changes_trie_config_V5(c, &method->basic.system_set_changes_trie_config_V5))
        break;
    case 6: /* module 0 call 6 */
        CHECK_ERROR(_readMethod_system_set_storage_V5(c, &method->basic.system_set_storage_V5))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_kill_storage_V5(c, &method->basic.system_kill_storage_V5))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_kill_prefix_V5(c, &method->basic.system_kill_prefix_V5))
        break;
    case 9: /* module 0 call 9 */
        CHECK_ERROR(_readMethod_system_suicide_V5(c, &method->basic.system_suicide_V5))
        break;
    case 256: /* module 1 call 0 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_V5(c, &method->basic.babe_report_equivocation_V5))
        break;
    case 257: /* module 1 call 1 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_unsigned_V5(c, &method->basic.babe_report_equivocation_unsigned_V5))
        break;
    case 512: /* module 2 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V5(c, &method->basic.timestamp_set_V5))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_indices_claim_V5(c, &method->basic.indices_claim_V5))
        break;
    case 769: /* module 3 call 1 */
        CHECK_ERROR(_readMethod_indices_transfer_V5(c, &method->basic.indices_transfer_V5))
        break;
    case 770: /* module 3 call 2 */
        CHECK_ERROR(_readMethod_indices_free_V5(c, &method->basic.indices_free_V5))
        break;
    case 771: /* module 3 call 3 */
        CHECK_ERROR(_readMethod_indices_force_transfer_V5(c, &method->basic.indices_force_transfer_V5))
        break;
    case 772: /* module 3 call 4 */
        CHECK_ERROR(_readMethod_indices_freeze_V5(c, &method->basic.indices_freeze_V5))
        break;
    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V5(c, &method->basic.balances_transfer_V5))
        break;
    case 1025: /* module 4 call 1 */
        CHECK_ERROR(_readMethod_balances_transfer_with_memo_V5(c, &method->basic.balances_transfer_with_memo_V5))
        break;
    case 1026: /* module 4 call 2 */
        CHECK_ERROR(_readMethod_balances_deposit_block_reward_reserve_balance_V5(c, &method->basic.balances_deposit_block_reward_reserve_balance_V5))
        break;
    case 1027: /* module 4 call 3 */
        CHECK_ERROR(_readMethod_balances_set_balance_V5(c, &method->basic.balances_set_balance_V5))
        break;
    case 1028: /* module 4 call 4 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V5(c, &method->basic.balances_force_transfer_V5))
        break;
    case 1029: /* module 4 call 5 */
        CHECK_ERROR(_readMethod_balances_burn_account_balance_V5(c, &method->basic.balances_burn_account_balance_V5))
        break;
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_identity_register_did_V5(c, &method->basic.identity_register_did_V5))
        break;
    case 1537: /* module 6 call 1 */
        CHECK_ERROR(_readMethod_identity_cdd_register_did_V5(c, &method->basic.identity_cdd_register_did_V5))
        break;
    case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_identity_mock_cdd_register_did_V5(c, &method->basic.identity_mock_cdd_register_did_V5))
        break;
    case 1539: /* module 6 call 3 */
        CHECK_ERROR(_readMethod_identity_invalidate_cdd_claims_V5(c, &method->basic.identity_invalidate_cdd_claims_V5))
        break;
    case 1540: /* module 6 call 4 */
        CHECK_ERROR(_readMethod_identity_remove_secondary_keys_V5(c, &method->basic.identity_remove_secondary_keys_V5))
        break;
    case 1541: /* module 6 call 5 */
        CHECK_ERROR(_readMethod_identity_accept_primary_key_V5(c, &method->basic.identity_accept_primary_key_V5))
        break;
    case 1542: /* module 6 call 6 */
        CHECK_ERROR(_readMethod_identity_change_cdd_requirement_for_mk_rotation_V5(c, &method->basic.identity_change_cdd_requirement_for_mk_rotation_V5))
        break;
    case 1543: /* module 6 call 7 */
        CHECK_ERROR(_readMethod_identity_join_identity_as_key_V5(c, &method->basic.identity_join_identity_as_key_V5))
        break;
    case 1544: /* module 6 call 8 */
        CHECK_ERROR(_readMethod_identity_join_identity_as_identity_V5(c, &method->basic.identity_join_identity_as_identity_V5))
        break;
    case 1545: /* module 6 call 9 */
        CHECK_ERROR(_readMethod_identity_leave_identity_as_key_V5(c, &method->basic.identity_leave_identity_as_key_V5))
        break;
    case 1546: /* module 6 call 10 */
        CHECK_ERROR(_readMethod_identity_leave_identity_as_identity_V5(c, &method->basic.identity_leave_identity_as_identity_V5))
        break;
    case 1547: /* module 6 call 11 */
        CHECK_ERROR(_readMethod_identity_add_claim_V5(c, &method->basic.identity_add_claim_V5))
        break;
    case 1548: /* module 6 call 12 */
        CHECK_ERROR(_readMethod_identity_forwarded_call_V5(c, &method->nested.identity_forwarded_call_V5))
        break;
    case 1549: /* module 6 call 13 */
        CHECK_ERROR(_readMethod_identity_revoke_claim_V5(c, &method->basic.identity_revoke_claim_V5))
        break;
    case 1550: /* module 6 call 14 */
        CHECK_ERROR(_readMethod_identity_set_permission_to_signer_V5(c, &method->basic.identity_set_permission_to_signer_V5))
        break;
    case 1551: /* module 6 call 15 */
        CHECK_ERROR(_readMethod_identity_legacy_set_permission_to_signer_V5(c, &method->basic.identity_legacy_set_permission_to_signer_V5))
        break;
    case 1552: /* module 6 call 16 */
        CHECK_ERROR(_readMethod_identity_freeze_secondary_keys_V5(c, &method->basic.identity_freeze_secondary_keys_V5))
        break;
    case 1553: /* module 6 call 17 */
        CHECK_ERROR(_readMethod_identity_unfreeze_secondary_keys_V5(c, &method->basic.identity_unfreeze_secondary_keys_V5))
        break;
    case 1554: /* module 6 call 18 */
        CHECK_ERROR(_readMethod_identity_get_my_did_V5(c, &method->basic.identity_get_my_did_V5))
        break;
    case 1555: /* module 6 call 19 */
        CHECK_ERROR(_readMethod_identity_get_cdd_of_V5(c, &method->basic.identity_get_cdd_of_V5))
        break;
    case 1556: /* module 6 call 20 */
        CHECK_ERROR(_readMethod_identity_add_authorization_V5(c, &method->basic.identity_add_authorization_V5))
        break;
    case 1557: /* module 6 call 21 */
        CHECK_ERROR(_readMethod_identity_remove_authorization_V5(c, &method->basic.identity_remove_authorization_V5))
        break;
    case 1558: /* module 6 call 22 */
        CHECK_ERROR(_readMethod_identity_accept_authorization_V5(c, &method->basic.identity_accept_authorization_V5))
        break;
    case 1559: /* module 6 call 23 */
        CHECK_ERROR(_readMethod_identity_add_secondary_keys_with_authorization_V5(c, &method->basic.identity_add_secondary_keys_with_authorization_V5))
        break;
    case 1560: /* module 6 call 24 */
        CHECK_ERROR(_readMethod_identity_revoke_offchain_authorization_V5(c, &method->basic.identity_revoke_offchain_authorization_V5))
        break;
    case 1561: /* module 6 call 25 */
        CHECK_ERROR(_readMethod_identity_add_investor_uniqueness_claim_V5(c, &method->basic.identity_add_investor_uniqueness_claim_V5))
        break;
    case 1562: /* module 6 call 26 */
        CHECK_ERROR(_readMethod_identity_gc_add_cdd_claim_V5(c, &method->basic.identity_gc_add_cdd_claim_V5))
        break;
    case 1563: /* module 6 call 27 */
        CHECK_ERROR(_readMethod_identity_gc_revoke_cdd_claim_V5(c, &method->basic.identity_gc_revoke_cdd_claim_V5))
        break;
    case 1792: /* module 7 call 0 */
        CHECK_ERROR(_readMethod_authorship_set_uncles_V5(c, &method->basic.authorship_set_uncles_V5))
        break;
    case 2048: /* module 8 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V5(c, &method->basic.staking_bond_V5))
        break;
    case 2049: /* module 8 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V5(c, &method->basic.staking_bond_extra_V5))
        break;
    case 2050: /* module 8 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V5(c, &method->basic.staking_unbond_V5))
        break;
    case 2051: /* module 8 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V5(c, &method->basic.staking_withdraw_unbonded_V5))
        break;
    case 2052: /* module 8 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V5(c, &method->basic.staking_validate_V5))
        break;
    case 2053: /* module 8 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V5(c, &method->basic.staking_nominate_V5))
        break;
    case 2054: /* module 8 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V5(c, &method->basic.staking_chill_V5))
        break;
    case 2055: /* module 8 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V5(c, &method->basic.staking_set_payee_V5))
        break;
    case 2056: /* module 8 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V5(c, &method->basic.staking_set_controller_V5))
        break;
    case 2057: /* module 8 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V5(c, &method->basic.staking_set_validator_count_V5))
        break;
    case 2058: /* module 8 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V5(c, &method->basic.staking_increase_validator_count_V5))
        break;
    case 2059: /* module 8 call 11 */
        CHECK_ERROR(_readMethod_staking_scale_validator_count_V5(c, &method->basic.staking_scale_validator_count_V5))
        break;
    case 2060: /* module 8 call 12 */
        CHECK_ERROR(_readMethod_staking_add_permissioned_validator_V5(c, &method->basic.staking_add_permissioned_validator_V5))
        break;
    case 2061: /* module 8 call 13 */
        CHECK_ERROR(_readMethod_staking_remove_permissioned_validator_V5(c, &method->basic.staking_remove_permissioned_validator_V5))
        break;
    case 2062: /* module 8 call 14 */
        CHECK_ERROR(_readMethod_staking_validate_cdd_expiry_nominators_V5(c, &method->basic.staking_validate_cdd_expiry_nominators_V5))
        break;
    case 2063: /* module 8 call 15 */
        CHECK_ERROR(_readMethod_staking_set_commission_cap_V5(c, &method->basic.staking_set_commission_cap_V5))
        break;
    case 2064: /* module 8 call 16 */
        CHECK_ERROR(_readMethod_staking_set_min_bond_threshold_V5(c, &method->basic.staking_set_min_bond_threshold_V5))
        break;
    case 2065: /* module 8 call 17 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V5(c, &method->basic.staking_force_no_eras_V5))
        break;
    case 2066: /* module 8 call 18 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V5(c, &method->basic.staking_force_new_era_V5))
        break;
    case 2067: /* module 8 call 19 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V5(c, &method->basic.staking_set_invulnerables_V5))
        break;
    case 2068: /* module 8 call 20 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V5(c, &method->basic.staking_force_unstake_V5))
        break;
    case 2069: /* module 8 call 21 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V5(c, &method->basic.staking_force_new_era_always_V5))
        break;
    case 2070: /* module 8 call 22 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V5(c, &method->basic.staking_cancel_deferred_slash_V5))
        break;
    case 2071: /* module 8 call 23 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V5(c, &method->basic.staking_payout_stakers_V5))
        break;
    case 2072: /* module 8 call 24 */
        CHECK_ERROR(_readMethod_staking_rebond_V5(c, &method->basic.staking_rebond_V5))
        break;
    case 2073: /* module 8 call 25 */
        CHECK_ERROR(_readMethod_staking_set_history_depth_V5(c, &method->basic.staking_set_history_depth_V5))
        break;
    case 2074: /* module 8 call 26 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V5(c, &method->basic.staking_reap_stash_V5))
        break;
    case 2075: /* module 8 call 27 */
        CHECK_ERROR(_readMethod_staking_submit_election_solution_V5(c, &method->basic.staking_submit_election_solution_V5))
        break;
    case 2076: /* module 8 call 28 */
        CHECK_ERROR(_readMethod_staking_submit_election_solution_unsigned_V5(c, &method->basic.staking_submit_election_solution_unsigned_V5))
        break;
    case 2077: /* module 8 call 29 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_by_system_V5(c, &method->basic.staking_payout_stakers_by_system_V5))
        break;
    case 2078: /* module 8 call 30 */
        CHECK_ERROR(_readMethod_staking_change_slashing_allowed_for_V5(c, &method->basic.staking_change_slashing_allowed_for_V5))
        break;
    case 2079: /* module 8 call 31 */
        CHECK_ERROR(_readMethod_staking_update_permissioned_validator_intended_count_V5(c, &method->basic.staking_update_permissioned_validator_intended_count_V5))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V5(c, &method->basic.session_set_keys_V5))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V5(c, &method->basic.session_purge_keys_V5))
        break;
    case 2816: /* module 11 call 0 */
        CHECK_ERROR(_readMethod_finalitytracker_final_hint_V5(c, &method->basic.finalitytracker_final_hint_V5))
        break;
    case 3072: /* module 12 call 0 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_V5(c, &method->basic.grandpa_report_equivocation_V5))
        break;
    case 3073: /* module 12 call 1 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_unsigned_V5(c, &method->basic.grandpa_report_equivocation_unsigned_V5))
        break;
    case 3074: /* module 12 call 2 */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V5(c, &method->basic.grandpa_note_stalled_V5))
        break;
    case 3328: /* module 13 call 0 */
        CHECK_ERROR(_readMethod_imonline_heartbeat_V5(c, &method->basic.imonline_heartbeat_V5))
        break;
    case 3329: /* module 13 call 1 */
        CHECK_ERROR(_readMethod_imonline_set_slashing_params_V5(c, &method->basic.imonline_set_slashing_params_V5))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_sudo_sudo_V5(c, &method->nested.sudo_sudo_V5))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_sudo_sudo_unchecked_weight_V5(c, &method->nested.sudo_sudo_unchecked_weight_V5))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_sudo_set_key_V5(c, &method->basic.sudo_set_key_V5))
        break;
    case 4355: /* module 17 call 3 */
        CHECK_ERROR(_readMethod_sudo_sudo_as_V5(c, &method->nested.sudo_sudo_as_V5))
        break;
    case 4608: /* module 18 call 0 */
        CHECK_ERROR(_readMethod_multisig_create_multisig_V5(c, &method->basic.multisig_create_multisig_V5))
        break;
    case 4609: /* module 18 call 1 */
        CHECK_ERROR(_readMethod_multisig_create_or_approve_proposal_as_identity_V5(c, &method->nested.multisig_create_or_approve_proposal_as_identity_V5))
        break;
    case 4610: /* module 18 call 2 */
        CHECK_ERROR(_readMethod_multisig_create_or_approve_proposal_as_key_V5(c, &method->nested.multisig_create_or_approve_proposal_as_key_V5))
        break;
    case 4611: /* module 18 call 3 */
        CHECK_ERROR(_readMethod_multisig_create_proposal_as_identity_V5(c, &method->nested.multisig_create_proposal_as_identity_V5))
        break;
    case 4612: /* module 18 call 4 */
        CHECK_ERROR(_readMethod_multisig_create_proposal_as_key_V5(c, &method->nested.multisig_create_proposal_as_key_V5))
        break;
    case 4613: /* module 18 call 5 */
        CHECK_ERROR(_readMethod_multisig_approve_as_identity_V5(c, &method->basic.multisig_approve_as_identity_V5))
        break;
    case 4614: /* module 18 call 6 */
        CHECK_ERROR(_readMethod_multisig_approve_as_key_V5(c, &method->basic.multisig_approve_as_key_V5))
        break;
    case 4615: /* module 18 call 7 */
        CHECK_ERROR(_readMethod_multisig_reject_as_identity_V5(c, &method->basic.multisig_reject_as_identity_V5))
        break;
    case 4616: /* module 18 call 8 */
        CHECK_ERROR(_readMethod_multisig_reject_as_key_V5(c, &method->basic.multisig_reject_as_key_V5))
        break;
    case 4617: /* module 18 call 9 */
        CHECK_ERROR(_readMethod_multisig_accept_multisig_signer_as_identity_V5(c, &method->basic.multisig_accept_multisig_signer_as_identity_V5))
        break;
    case 4618: /* module 18 call 10 */
        CHECK_ERROR(_readMethod_multisig_accept_multisig_signer_as_key_V5(c, &method->basic.multisig_accept_multisig_signer_as_key_V5))
        break;
    case 4619: /* module 18 call 11 */
        CHECK_ERROR(_readMethod_multisig_add_multisig_signer_V5(c, &method->basic.multisig_add_multisig_signer_V5))
        break;
    case 4620: /* module 18 call 12 */
        CHECK_ERROR(_readMethod_multisig_remove_multisig_signer_V5(c, &method->basic.multisig_remove_multisig_signer_V5))
        break;
    case 4621: /* module 18 call 13 */
        CHECK_ERROR(_readMethod_multisig_add_multisig_signers_via_creator_V5(c, &method->basic.multisig_add_multisig_signers_via_creator_V5))
        break;
    case 4622: /* module 18 call 14 */
        CHECK_ERROR(_readMethod_multisig_remove_multisig_signers_via_creator_V5(c, &method->basic.multisig_remove_multisig_signers_via_creator_V5))
        break;
    case 4623: /* module 18 call 15 */
        CHECK_ERROR(_readMethod_multisig_change_sigs_required_V5(c, &method->basic.multisig_change_sigs_required_V5))
        break;
    case 4624: /* module 18 call 16 */
        CHECK_ERROR(_readMethod_multisig_make_multisig_signer_V5(c, &method->basic.multisig_make_multisig_signer_V5))
        break;
    case 4625: /* module 18 call 17 */
        CHECK_ERROR(_readMethod_multisig_make_multisig_primary_V5(c, &method->basic.multisig_make_multisig_primary_V5))
        break;
    case 4626: /* module 18 call 18 */
        CHECK_ERROR(_readMethod_multisig_execute_scheduled_proposal_V5(c, &method->basic.multisig_execute_scheduled_proposal_V5))
        break;
    case 5120: /* module 20 call 0 */
        CHECK_ERROR(_readMethod_contracts_update_schedule_V5(c, &method->basic.contracts_update_schedule_V5))
        break;
    case 5121: /* module 20 call 1 */
        CHECK_ERROR(_readMethod_contracts_put_code_V5(c, &method->basic.contracts_put_code_V5))
        break;
    case 5122: /* module 20 call 2 */
        CHECK_ERROR(_readMethod_contracts_call_V5(c, &method->basic.contracts_call_V5))
        break;
    case 5123: /* module 20 call 3 */
        CHECK_ERROR(_readMethod_contracts_instantiate_V5(c, &method->basic.contracts_instantiate_V5))
        break;
    case 5124: /* module 20 call 4 */
        CHECK_ERROR(_readMethod_contracts_freeze_instantiation_V5(c, &method->basic.contracts_freeze_instantiation_V5))
        break;
    case 5125: /* module 20 call 5 */
        CHECK_ERROR(_readMethod_contracts_unfreeze_instantiation_V5(c, &method->basic.contracts_unfreeze_instantiation_V5))
        break;
    case 5126: /* module 20 call 6 */
        CHECK_ERROR(_readMethod_contracts_transfer_template_ownership_V5(c, &method->basic.contracts_transfer_template_ownership_V5))
        break;
    case 5127: /* module 20 call 7 */
        CHECK_ERROR(_readMethod_contracts_change_template_fees_V5(c, &method->basic.contracts_change_template_fees_V5))
        break;
    case 5128: /* module 20 call 8 */
        CHECK_ERROR(_readMethod_contracts_change_template_meta_url_V5(c, &method->basic.contracts_change_template_meta_url_V5))
        break;
    case 5376: /* module 21 call 0 */
        CHECK_ERROR(_readMethod_treasury_disbursement_V5(c, &method->basic.treasury_disbursement_V5))
        break;
    case 5377: /* module 21 call 1 */
        CHECK_ERROR(_readMethod_treasury_reimbursement_V5(c, &method->basic.treasury_reimbursement_V5))
        break;
    case 5632: /* module 22 call 0 */
        CHECK_ERROR(_readMethod_polymeshcommittee_set_vote_threshold_V5(c, &method->basic.polymeshcommittee_set_vote_threshold_V5))
        break;
    case 5633: /* module 22 call 1 */
        CHECK_ERROR(_readMethod_polymeshcommittee_set_release_coordinator_V5(c, &method->basic.polymeshcommittee_set_release_coordinator_V5))
        break;
    case 5634: /* module 22 call 2 */
        CHECK_ERROR(_readMethod_polymeshcommittee_set_expires_after_V5(c, &method->basic.polymeshcommittee_set_expires_after_V5))
        break;
    case 5635: /* module 22 call 3 */
        CHECK_ERROR(_readMethod_polymeshcommittee_vote_or_propose_V5(c, &method->nested.polymeshcommittee_vote_or_propose_V5))
        break;
    case 5636: /* module 22 call 4 */
        CHECK_ERROR(_readMethod_polymeshcommittee_vote_V5(c, &method->basic.polymeshcommittee_vote_V5))
        break;
    case 5888: /* module 23 call 0 */
        CHECK_ERROR(_readMethod_committeemembership_set_active_members_limit_V5(c, &method->basic.committeemembership_set_active_members_limit_V5))
        break;
    case 5889: /* module 23 call 1 */
        CHECK_ERROR(_readMethod_committeemembership_disable_member_V5(c, &method->basic.committeemembership_disable_member_V5))
        break;
    case 5890: /* module 23 call 2 */
        CHECK_ERROR(_readMethod_committeemembership_add_member_V5(c, &method->basic.committeemembership_add_member_V5))
        break;
    case 5891: /* module 23 call 3 */
        CHECK_ERROR(_readMethod_committeemembership_remove_member_V5(c, &method->basic.committeemembership_remove_member_V5))
        break;
    case 5892: /* module 23 call 4 */
        CHECK_ERROR(_readMethod_committeemembership_swap_member_V5(c, &method->basic.committeemembership_swap_member_V5))
        break;
    case 5893: /* module 23 call 5 */
        CHECK_ERROR(_readMethod_committeemembership_reset_members_V5(c, &method->basic.committeemembership_reset_members_V5))
        break;
    case 5894: /* module 23 call 6 */
        CHECK_ERROR(_readMethod_committeemembership_abdicate_membership_V5(c, &method->basic.committeemembership_abdicate_membership_V5))
        break;
    case 6144: /* module 24 call 0 */
        CHECK_ERROR(_readMethod_pips_set_prune_historical_pips_V5(c, &method->basic.pips_set_prune_historical_pips_V5))
        break;
    case 6145: /* module 24 call 1 */
        CHECK_ERROR(_readMethod_pips_set_min_proposal_deposit_V5(c, &method->basic.pips_set_min_proposal_deposit_V5))
        break;
    case 6146: /* module 24 call 2 */
        CHECK_ERROR(_readMethod_pips_set_default_enactment_period_V5(c, &method->basic.pips_set_default_enactment_period_V5))
        break;
    case 6147: /* module 24 call 3 */
        CHECK_ERROR(_readMethod_pips_set_pending_pip_expiry_V5(c, &method->basic.pips_set_pending_pip_expiry_V5))
        break;
    case 6148: /* module 24 call 4 */
        CHECK_ERROR(_readMethod_pips_set_max_pip_skip_count_V5(c, &method->basic.pips_set_max_pip_skip_count_V5))
        break;
    case 6149: /* module 24 call 5 */
        CHECK_ERROR(_readMethod_pips_set_active_pip_limit_V5(c, &method->basic.pips_set_active_pip_limit_V5))
        break;
    case 6150: /* module 24 call 6 */
        CHECK_ERROR(_readMethod_pips_propose_V5(c, &method->nested.pips_propose_V5))
        break;
    case 6151: /* module 24 call 7 */
        CHECK_ERROR(_readMethod_pips_vote_V5(c, &method->basic.pips_vote_V5))
        break;
    case 6152: /* module 24 call 8 */
        CHECK_ERROR(_readMethod_pips_approve_committee_proposal_V5(c, &method->basic.pips_approve_committee_proposal_V5))
        break;
    case 6153: /* module 24 call 9 */
        CHECK_ERROR(_readMethod_pips_reject_proposal_V5(c, &method->basic.pips_reject_proposal_V5))
        break;
    case 6154: /* module 24 call 10 */
        CHECK_ERROR(_readMethod_pips_prune_proposal_V5(c, &method->basic.pips_prune_proposal_V5))
        break;
    case 6155: /* module 24 call 11 */
        CHECK_ERROR(_readMethod_pips_reschedule_execution_V5(c, &method->basic.pips_reschedule_execution_V5))
        break;
    case 6156: /* module 24 call 12 */
        CHECK_ERROR(_readMethod_pips_clear_snapshot_V5(c, &method->basic.pips_clear_snapshot_V5))
        break;
    case 6157: /* module 24 call 13 */
        CHECK_ERROR(_readMethod_pips_snapshot_V5(c, &method->basic.pips_snapshot_V5))
        break;
    case 6158: /* module 24 call 14 */
        CHECK_ERROR(_readMethod_pips_enact_snapshot_results_V5(c, &method->basic.pips_enact_snapshot_results_V5))
        break;
    case 6159: /* module 24 call 15 */
        CHECK_ERROR(_readMethod_pips_execute_scheduled_pip_V5(c, &method->basic.pips_execute_scheduled_pip_V5))
        break;
    case 6160: /* module 24 call 16 */
        CHECK_ERROR(_readMethod_pips_expire_scheduled_pip_V5(c, &method->basic.pips_expire_scheduled_pip_V5))
        break;
    case 6400: /* module 25 call 0 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_vote_threshold_V5(c, &method->basic.technicalcommittee_set_vote_threshold_V5))
        break;
    case 6401: /* module 25 call 1 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_release_coordinator_V5(c, &method->basic.technicalcommittee_set_release_coordinator_V5))
        break;
    case 6402: /* module 25 call 2 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_expires_after_V5(c, &method->basic.technicalcommittee_set_expires_after_V5))
        break;
    case 6403: /* module 25 call 3 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_or_propose_V5(c, &method->nested.technicalcommittee_vote_or_propose_V5))
        break;
    case 6404: /* module 25 call 4 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_V5(c, &method->basic.technicalcommittee_vote_V5))
        break;
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_set_active_members_limit_V5(c, &method->basic.technicalcommitteemembership_set_active_members_limit_V5))
        break;
    case 6657: /* module 26 call 1 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_disable_member_V5(c, &method->basic.technicalcommitteemembership_disable_member_V5))
        break;
    case 6658: /* module 26 call 2 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_add_member_V5(c, &method->basic.technicalcommitteemembership_add_member_V5))
        break;
    case 6659: /* module 26 call 3 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_remove_member_V5(c, &method->basic.technicalcommitteemembership_remove_member_V5))
        break;
    case 6660: /* module 26 call 4 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_swap_member_V5(c, &method->basic.technicalcommitteemembership_swap_member_V5))
        break;
    case 6661: /* module 26 call 5 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_reset_members_V5(c, &method->basic.technicalcommitteemembership_reset_members_V5))
        break;
    case 6662: /* module 26 call 6 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_abdicate_membership_V5(c, &method->basic.technicalcommitteemembership_abdicate_membership_V5))
        break;
    case 6912: /* module 27 call 0 */
        CHECK_ERROR(_readMethod_upgradecommittee_set_vote_threshold_V5(c, &method->basic.upgradecommittee_set_vote_threshold_V5))
        break;
    case 6913: /* module 27 call 1 */
        CHECK_ERROR(_readMethod_upgradecommittee_set_release_coordinator_V5(c, &method->basic.upgradecommittee_set_release_coordinator_V5))
        break;
    case 6914: /* module 27 call 2 */
        CHECK_ERROR(_readMethod_upgradecommittee_set_expires_after_V5(c, &method->basic.upgradecommittee_set_expires_after_V5))
        break;
    case 6915: /* module 27 call 3 */
        CHECK_ERROR(_readMethod_upgradecommittee_vote_or_propose_V5(c, &method->nested.upgradecommittee_vote_or_propose_V5))
        break;
    case 6916: /* module 27 call 4 */
        CHECK_ERROR(_readMethod_upgradecommittee_vote_V5(c, &method->basic.upgradecommittee_vote_V5))
        break;
    case 7168: /* module 28 call 0 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_set_active_members_limit_V5(c, &method->basic.upgradecommitteemembership_set_active_members_limit_V5))
        break;
    case 7169: /* module 28 call 1 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_disable_member_V5(c, &method->basic.upgradecommitteemembership_disable_member_V5))
        break;
    case 7170: /* module 28 call 2 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_add_member_V5(c, &method->basic.upgradecommitteemembership_add_member_V5))
        break;
    case 7171: /* module 28 call 3 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_remove_member_V5(c, &method->basic.upgradecommitteemembership_remove_member_V5))
        break;
    case 7172: /* module 28 call 4 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_swap_member_V5(c, &method->basic.upgradecommitteemembership_swap_member_V5))
        break;
    case 7173: /* module 28 call 5 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_reset_members_V5(c, &method->basic.upgradecommitteemembership_reset_members_V5))
        break;
    case 7174: /* module 28 call 6 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_abdicate_membership_V5(c, &method->basic.upgradecommitteemembership_abdicate_membership_V5))
        break;
    case 7424: /* module 29 call 0 */
        CHECK_ERROR(_readMethod_asset_register_ticker_V5(c, &method->basic.asset_register_ticker_V5))
        break;
    case 7425: /* module 29 call 1 */
        CHECK_ERROR(_readMethod_asset_accept_ticker_transfer_V5(c, &method->basic.asset_accept_ticker_transfer_V5))
        break;
    case 7426: /* module 29 call 2 */
        CHECK_ERROR(_readMethod_asset_accept_primary_issuance_agent_transfer_V5(c, &method->basic.asset_accept_primary_issuance_agent_transfer_V5))
        break;
    case 7427: /* module 29 call 3 */
        CHECK_ERROR(_readMethod_asset_accept_asset_ownership_transfer_V5(c, &method->basic.asset_accept_asset_ownership_transfer_V5))
        break;
    case 7428: /* module 29 call 4 */
        CHECK_ERROR(_readMethod_asset_create_asset_V5(c, &method->basic.asset_create_asset_V5))
        break;
    case 7429: /* module 29 call 5 */
        CHECK_ERROR(_readMethod_asset_freeze_V5(c, &method->basic.asset_freeze_V5))
        break;
    case 7430: /* module 29 call 6 */
        CHECK_ERROR(_readMethod_asset_unfreeze_V5(c, &method->basic.asset_unfreeze_V5))
        break;
    case 7431: /* module 29 call 7 */
        CHECK_ERROR(_readMethod_asset_rename_asset_V5(c, &method->basic.asset_rename_asset_V5))
        break;
    case 7432: /* module 29 call 8 */
        CHECK_ERROR(_readMethod_asset_issue_V5(c, &method->basic.asset_issue_V5))
        break;
    case 7433: /* module 29 call 9 */
        CHECK_ERROR(_readMethod_asset_redeem_V5(c, &method->basic.asset_redeem_V5))
        break;
    case 7434: /* module 29 call 10 */
        CHECK_ERROR(_readMethod_asset_make_divisible_V5(c, &method->basic.asset_make_divisible_V5))
        break;
    case 7435: /* module 29 call 11 */
        CHECK_ERROR(_readMethod_asset_add_documents_V5(c, &method->basic.asset_add_documents_V5))
        break;
    case 7436: /* module 29 call 12 */
        CHECK_ERROR(_readMethod_asset_remove_documents_V5(c, &method->basic.asset_remove_documents_V5))
        break;
    case 7437: /* module 29 call 13 */
        CHECK_ERROR(_readMethod_asset_set_funding_round_V5(c, &method->basic.asset_set_funding_round_V5))
        break;
    case 7438: /* module 29 call 14 */
        CHECK_ERROR(_readMethod_asset_update_identifiers_V5(c, &method->basic.asset_update_identifiers_V5))
        break;
    case 7439: /* module 29 call 15 */
        CHECK_ERROR(_readMethod_asset_add_extension_V5(c, &method->basic.asset_add_extension_V5))
        break;
    case 7440: /* module 29 call 16 */
        CHECK_ERROR(_readMethod_asset_archive_extension_V5(c, &method->basic.asset_archive_extension_V5))
        break;
    case 7441: /* module 29 call 17 */
        CHECK_ERROR(_readMethod_asset_unarchive_extension_V5(c, &method->basic.asset_unarchive_extension_V5))
        break;
    case 7442: /* module 29 call 18 */
        CHECK_ERROR(_readMethod_asset_remove_primary_issuance_agent_V5(c, &method->basic.asset_remove_primary_issuance_agent_V5))
        break;
    case 7443: /* module 29 call 19 */
        CHECK_ERROR(_readMethod_asset_remove_smart_extension_V5(c, &method->basic.asset_remove_smart_extension_V5))
        break;
    case 7444: /* module 29 call 20 */
        CHECK_ERROR(_readMethod_asset_claim_classic_ticker_V5(c, &method->basic.asset_claim_classic_ticker_V5))
        break;
    case 7445: /* module 29 call 21 */
        CHECK_ERROR(_readMethod_asset_reserve_classic_ticker_V5(c, &method->basic.asset_reserve_classic_ticker_V5))
        break;
    case 7936: /* module 31 call 0 */
        CHECK_ERROR(_readMethod_bridge_change_controller_V5(c, &method->basic.bridge_change_controller_V5))
        break;
    case 7937: /* module 31 call 1 */
        CHECK_ERROR(_readMethod_bridge_change_admin_V5(c, &method->basic.bridge_change_admin_V5))
        break;
    case 7938: /* module 31 call 2 */
        CHECK_ERROR(_readMethod_bridge_change_timelock_V5(c, &method->basic.bridge_change_timelock_V5))
        break;
    case 7939: /* module 31 call 3 */
        CHECK_ERROR(_readMethod_bridge_freeze_V5(c, &method->basic.bridge_freeze_V5))
        break;
    case 7940: /* module 31 call 4 */
        CHECK_ERROR(_readMethod_bridge_unfreeze_V5(c, &method->basic.bridge_unfreeze_V5))
        break;
    case 7941: /* module 31 call 5 */
        CHECK_ERROR(_readMethod_bridge_change_bridge_limit_V5(c, &method->basic.bridge_change_bridge_limit_V5))
        break;
    case 7942: /* module 31 call 6 */
        CHECK_ERROR(_readMethod_bridge_change_bridge_exempted_V5(c, &method->basic.bridge_change_bridge_exempted_V5))
        break;
    case 7943: /* module 31 call 7 */
        CHECK_ERROR(_readMethod_bridge_force_handle_bridge_tx_V5(c, &method->basic.bridge_force_handle_bridge_tx_V5))
        break;
    case 7944: /* module 31 call 8 */
        CHECK_ERROR(_readMethod_bridge_batch_propose_bridge_tx_V5(c, &method->basic.bridge_batch_propose_bridge_tx_V5))
        break;
    case 7945: /* module 31 call 9 */
        CHECK_ERROR(_readMethod_bridge_propose_bridge_tx_V5(c, &method->basic.bridge_propose_bridge_tx_V5))
        break;
    case 7946: /* module 31 call 10 */
        CHECK_ERROR(_readMethod_bridge_handle_bridge_tx_V5(c, &method->basic.bridge_handle_bridge_tx_V5))
        break;
    case 7947: /* module 31 call 11 */
        CHECK_ERROR(_readMethod_bridge_freeze_txs_V5(c, &method->basic.bridge_freeze_txs_V5))
        break;
    case 7948: /* module 31 call 12 */
        CHECK_ERROR(_readMethod_bridge_unfreeze_txs_V5(c, &method->basic.bridge_unfreeze_txs_V5))
        break;
    case 7949: /* module 31 call 13 */
        CHECK_ERROR(_readMethod_bridge_handle_scheduled_bridge_tx_V5(c, &method->basic.bridge_handle_scheduled_bridge_tx_V5))
        break;
    case 8192: /* module 32 call 0 */
        CHECK_ERROR(_readMethod_compliancemanager_add_compliance_requirement_V5(c, &method->basic.compliancemanager_add_compliance_requirement_V5))
        break;
    case 8193: /* module 32 call 1 */
        CHECK_ERROR(_readMethod_compliancemanager_remove_compliance_requirement_V5(c, &method->basic.compliancemanager_remove_compliance_requirement_V5))
        break;
    case 8194: /* module 32 call 2 */
        CHECK_ERROR(_readMethod_compliancemanager_replace_asset_compliance_V5(c, &method->basic.compliancemanager_replace_asset_compliance_V5))
        break;
    case 8195: /* module 32 call 3 */
        CHECK_ERROR(_readMethod_compliancemanager_reset_asset_compliance_V5(c, &method->basic.compliancemanager_reset_asset_compliance_V5))
        break;
    case 8196: /* module 32 call 4 */
        CHECK_ERROR(_readMethod_compliancemanager_pause_asset_compliance_V5(c, &method->basic.compliancemanager_pause_asset_compliance_V5))
        break;
    case 8197: /* module 32 call 5 */
        CHECK_ERROR(_readMethod_compliancemanager_resume_asset_compliance_V5(c, &method->basic.compliancemanager_resume_asset_compliance_V5))
        break;
    case 8198: /* module 32 call 6 */
        CHECK_ERROR(_readMethod_compliancemanager_add_default_trusted_claim_issuer_V5(c, &method->basic.compliancemanager_add_default_trusted_claim_issuer_V5))
        break;
    case 8199: /* module 32 call 7 */
        CHECK_ERROR(_readMethod_compliancemanager_remove_default_trusted_claim_issuer_V5(c, &method->basic.compliancemanager_remove_default_trusted_claim_issuer_V5))
        break;
    case 8200: /* module 32 call 8 */
        CHECK_ERROR(_readMethod_compliancemanager_change_compliance_requirement_V5(c, &method->basic.compliancemanager_change_compliance_requirement_V5))
        break;
    case 9216: /* module 36 call 0 */
        CHECK_ERROR(_readMethod_settlement_create_venue_V5(c, &method->basic.settlement_create_venue_V5))
        break;
    case 9217: /* module 36 call 1 */
        CHECK_ERROR(_readMethod_settlement_update_venue_V5(c, &method->basic.settlement_update_venue_V5))
        break;
    case 9218: /* module 36 call 2 */
        CHECK_ERROR(_readMethod_settlement_add_instruction_V5(c, &method->basic.settlement_add_instruction_V5))
        break;
    case 9219: /* module 36 call 3 */
        CHECK_ERROR(_readMethod_settlement_add_and_affirm_instruction_V5(c, &method->basic.settlement_add_and_affirm_instruction_V5))
        break;
    case 9220: /* module 36 call 4 */
        CHECK_ERROR(_readMethod_settlement_affirm_instruction_V5(c, &method->basic.settlement_affirm_instruction_V5))
        break;
    case 9221: /* module 36 call 5 */
        CHECK_ERROR(_readMethod_settlement_withdraw_affirmation_V5(c, &method->basic.settlement_withdraw_affirmation_V5))
        break;
    case 9222: /* module 36 call 6 */
        CHECK_ERROR(_readMethod_settlement_reject_instruction_V5(c, &method->basic.settlement_reject_instruction_V5))
        break;
    case 9223: /* module 36 call 7 */
        CHECK_ERROR(_readMethod_settlement_affirm_with_receipts_V5(c, &method->basic.settlement_affirm_with_receipts_V5))
        break;
    case 9224: /* module 36 call 8 */
        CHECK_ERROR(_readMethod_settlement_claim_receipt_V5(c, &method->basic.settlement_claim_receipt_V5))
        break;
    case 9225: /* module 36 call 9 */
        CHECK_ERROR(_readMethod_settlement_unclaim_receipt_V5(c, &method->basic.settlement_unclaim_receipt_V5))
        break;
    case 9226: /* module 36 call 10 */
        CHECK_ERROR(_readMethod_settlement_set_venue_filtering_V5(c, &method->basic.settlement_set_venue_filtering_V5))
        break;
    case 9227: /* module 36 call 11 */
        CHECK_ERROR(_readMethod_settlement_allow_venues_V5(c, &method->basic.settlement_allow_venues_V5))
        break;
    case 9228: /* module 36 call 12 */
        CHECK_ERROR(_readMethod_settlement_disallow_venues_V5(c, &method->basic.settlement_disallow_venues_V5))
        break;
    case 9229: /* module 36 call 13 */
        CHECK_ERROR(_readMethod_settlement_execute_scheduled_instruction_V5(c, &method->basic.settlement_execute_scheduled_instruction_V5))
        break;
    case 9472: /* module 37 call 0 */
        CHECK_ERROR(_readMethod_sto_create_fundraiser_V5(c, &method->basic.sto_create_fundraiser_V5))
        break;
    case 9473: /* module 37 call 1 */
        CHECK_ERROR(_readMethod_sto_invest_V5(c, &method->basic.sto_invest_V5))
        break;
    case 9474: /* module 37 call 2 */
        CHECK_ERROR(_readMethod_sto_freeze_fundraiser_V5(c, &method->basic.sto_freeze_fundraiser_V5))
        break;
    case 9475: /* module 37 call 3 */
        CHECK_ERROR(_readMethod_sto_unfreeze_fundraiser_V5(c, &method->basic.sto_unfreeze_fundraiser_V5))
        break;
    case 9476: /* module 37 call 4 */
        CHECK_ERROR(_readMethod_sto_modify_fundraiser_window_V5(c, &method->basic.sto_modify_fundraiser_window_V5))
        break;
    case 9477: /* module 37 call 5 */
        CHECK_ERROR(_readMethod_sto_stop_V5(c, &method->basic.sto_stop_V5))
        break;
    case 9728: /* module 38 call 0 */
        CHECK_ERROR(_readMethod_cddserviceproviders_set_active_members_limit_V5(c, &method->basic.cddserviceproviders_set_active_members_limit_V5))
        break;
    case 9729: /* module 38 call 1 */
        CHECK_ERROR(_readMethod_cddserviceproviders_disable_member_V5(c, &method->basic.cddserviceproviders_disable_member_V5))
        break;
    case 9730: /* module 38 call 2 */
        CHECK_ERROR(_readMethod_cddserviceproviders_add_member_V5(c, &method->basic.cddserviceproviders_add_member_V5))
        break;
    case 9731: /* module 38 call 3 */
        CHECK_ERROR(_readMethod_cddserviceproviders_remove_member_V5(c, &method->basic.cddserviceproviders_remove_member_V5))
        break;
    case 9732: /* module 38 call 4 */
        CHECK_ERROR(_readMethod_cddserviceproviders_swap_member_V5(c, &method->basic.cddserviceproviders_swap_member_V5))
        break;
    case 9733: /* module 38 call 5 */
        CHECK_ERROR(_readMethod_cddserviceproviders_reset_members_V5(c, &method->basic.cddserviceproviders_reset_members_V5))
        break;
    case 9734: /* module 38 call 6 */
        CHECK_ERROR(_readMethod_cddserviceproviders_abdicate_membership_V5(c, &method->basic.cddserviceproviders_abdicate_membership_V5))
        break;
    case 9984: /* module 39 call 0 */
        CHECK_ERROR(_readMethod_statistics_add_transfer_manager_V5(c, &method->basic.statistics_add_transfer_manager_V5))
        break;
    case 9985: /* module 39 call 1 */
        CHECK_ERROR(_readMethod_statistics_remove_transfer_manager_V5(c, &method->basic.statistics_remove_transfer_manager_V5))
        break;
    case 9986: /* module 39 call 2 */
        CHECK_ERROR(_readMethod_statistics_add_exempted_entities_V5(c, &method->basic.statistics_add_exempted_entities_V5))
        break;
    case 9987: /* module 39 call 3 */
        CHECK_ERROR(_readMethod_statistics_remove_exempted_entities_V5(c, &method->basic.statistics_remove_exempted_entities_V5))
        break;
    case 10240: /* module 40 call 0 */
        CHECK_ERROR(_readMethod_protocolfee_change_coefficient_V5(c, &method->basic.protocolfee_change_coefficient_V5))
        break;
    case 10241: /* module 40 call 1 */
        CHECK_ERROR(_readMethod_protocolfee_change_base_fee_V5(c, &method->basic.protocolfee_change_base_fee_V5))
        break;
    case 10496: /* module 41 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V5(c, &method->basic.utility_batch_V5))
        break;
    case 10497: /* module 41 call 1 */
        CHECK_ERROR(_readMethod_utility_batch_atomic_V5(c, &method->basic.utility_batch_atomic_V5))
        break;
    case 10498: /* module 41 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_optimistic_V5(c, &method->basic.utility_batch_optimistic_V5))
        break;
    case 10499: /* module 41 call 3 */
        CHECK_ERROR(_readMethod_utility_relay_tx_V5(c, &method->basic.utility_relay_tx_V5))
        break;
    case 10752: /* module 42 call 0 */
        CHECK_ERROR(_readMethod_portfolio_create_portfolio_V5(c, &method->basic.portfolio_create_portfolio_V5))
        break;
    case 10753: /* module 42 call 1 */
        CHECK_ERROR(_readMethod_portfolio_delete_portfolio_V5(c, &method->basic.portfolio_delete_portfolio_V5))
        break;
    case 10754: /* module 42 call 2 */
        CHECK_ERROR(_readMethod_portfolio_move_portfolio_funds_V5(c, &method->basic.portfolio_move_portfolio_funds_V5))
        break;
    case 10755: /* module 42 call 3 */
        CHECK_ERROR(_readMethod_portfolio_rename_portfolio_V5(c, &method->basic.portfolio_rename_portfolio_V5))
        break;
    case 11008: /* module 43 call 0 */
        CHECK_ERROR(_readMethod_confidential_add_range_proof_V5(c, &method->basic.confidential_add_range_proof_V5))
        break;
    case 11009: /* module 43 call 1 */
        CHECK_ERROR(_readMethod_confidential_add_verify_range_proof_V5(c, &method->basic.confidential_add_verify_range_proof_V5))
        break;
    case 11520: /* module 45 call 0 */
        CHECK_ERROR(_readMethod_scheduler_schedule_V5(c, &method->nested.scheduler_schedule_V5))
        break;
    case 11521: /* module 45 call 1 */
        CHECK_ERROR(_readMethod_scheduler_cancel_V5(c, &method->basic.scheduler_cancel_V5))
        break;
    case 11522: /* module 45 call 2 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_V5(c, &method->nested.scheduler_schedule_named_V5))
        break;
    case 11523: /* module 45 call 3 */
        CHECK_ERROR(_readMethod_scheduler_cancel_named_V5(c, &method->basic.scheduler_cancel_named_V5))
        break;
    case 11524: /* module 45 call 4 */
        CHECK_ERROR(_readMethod_scheduler_schedule_after_V5(c, &method->nested.scheduler_schedule_after_V5))
        break;
    case 11525: /* module 45 call 5 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_after_V5(c, &method->nested.scheduler_schedule_named_after_V5))
        break;
    case 11776: /* module 46 call 0 */
        CHECK_ERROR(_readMethod_corporateaction_set_max_details_length_V5(c, &method->basic.corporateaction_set_max_details_length_V5))
        break;
    case 11777: /* module 46 call 1 */
        CHECK_ERROR(_readMethod_corporateaction_reset_caa_V5(c, &method->basic.corporateaction_reset_caa_V5))
        break;
    case 11778: /* module 46 call 2 */
        CHECK_ERROR(_readMethod_corporateaction_set_default_targets_V5(c, &method->basic.corporateaction_set_default_targets_V5))
        break;
    case 11779: /* module 46 call 3 */
        CHECK_ERROR(_readMethod_corporateaction_set_default_withholding_tax_V5(c, &method->basic.corporateaction_set_default_withholding_tax_V5))
        break;
    case 11780: /* module 46 call 4 */
        CHECK_ERROR(_readMethod_corporateaction_set_did_withholding_tax_V5(c, &method->basic.corporateaction_set_did_withholding_tax_V5))
        break;
    case 11781: /* module 46 call 5 */
        CHECK_ERROR(_readMethod_corporateaction_initiate_corporate_action_V5(c, &method->basic.corporateaction_initiate_corporate_action_V5))
        break;
    case 11782: /* module 46 call 6 */
        CHECK_ERROR(_readMethod_corporateaction_link_ca_doc_V5(c, &method->basic.corporateaction_link_ca_doc_V5))
        break;
    case 11783: /* module 46 call 7 */
        CHECK_ERROR(_readMethod_corporateaction_remove_ca_V5(c, &method->basic.corporateaction_remove_ca_V5))
        break;
    case 11784: /* module 46 call 8 */
        CHECK_ERROR(_readMethod_corporateaction_change_record_date_V5(c, &method->basic.corporateaction_change_record_date_V5))
        break;
    case 12032: /* module 47 call 0 */
        CHECK_ERROR(_readMethod_corporateballot_attach_ballot_V5(c, &method->basic.corporateballot_attach_ballot_V5))
        break;
    case 12033: /* module 47 call 1 */
        CHECK_ERROR(_readMethod_corporateballot_vote_V5(c, &method->basic.corporateballot_vote_V5))
        break;
    case 12034: /* module 47 call 2 */
        CHECK_ERROR(_readMethod_corporateballot_change_end_V5(c, &method->basic.corporateballot_change_end_V5))
        break;
    case 12035: /* module 47 call 3 */
        CHECK_ERROR(_readMethod_corporateballot_change_meta_V5(c, &method->basic.corporateballot_change_meta_V5))
        break;
    case 12036: /* module 47 call 4 */
        CHECK_ERROR(_readMethod_corporateballot_change_rcv_V5(c, &method->basic.corporateballot_change_rcv_V5))
        break;
    case 12037: /* module 47 call 5 */
        CHECK_ERROR(_readMethod_corporateballot_remove_ballot_V5(c, &method->basic.corporateballot_remove_ballot_V5))
        break;
    case 12288: /* module 48 call 0 */
        CHECK_ERROR(_readMethod_capitaldistribution_distribute_V5(c, &method->basic.capitaldistribution_distribute_V5))
        break;
    case 12289: /* module 48 call 1 */
        CHECK_ERROR(_readMethod_capitaldistribution_claim_V5(c, &method->basic.capitaldistribution_claim_V5))
        break;
    case 12290: /* module 48 call 2 */
        CHECK_ERROR(_readMethod_capitaldistribution_push_benefit_V5(c, &method->basic.capitaldistribution_push_benefit_V5))
        break;
    case 12291: /* module 48 call 3 */
        CHECK_ERROR(_readMethod_capitaldistribution_reclaim_V5(c, &method->basic.capitaldistribution_reclaim_V5))
        break;
    case 12292: /* module 48 call 4 */
        CHECK_ERROR(_readMethod_capitaldistribution_remove_distribution_V5(c, &method->basic.capitaldistribution_remove_distribution_V5))
        break;
    case 12544: /* module 49 call 0 */
        CHECK_ERROR(_readMethod_checkpoint_create_checkpoint_V5(c, &method->basic.checkpoint_create_checkpoint_V5))
        break;
    case 12545: /* module 49 call 1 */
        CHECK_ERROR(_readMethod_checkpoint_set_schedules_max_complexity_V5(c, &method->basic.checkpoint_set_schedules_max_complexity_V5))
        break;
    case 12546: /* module 49 call 2 */
        CHECK_ERROR(_readMethod_checkpoint_create_schedule_V5(c, &method->basic.checkpoint_create_schedule_V5))
        break;
    case 12547: /* module 49 call 3 */
        CHECK_ERROR(_readMethod_checkpoint_remove_schedule_V5(c, &method->basic.checkpoint_remove_schedule_V5))
        break;
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V5(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 0:
        return "System";
    case 1:
        return "Babe";
    case 2:
        return "Timestamp";
    case 3:
        return "Indices";
    case 4:
        return "Balances";
    case 6:
        return "Identity";
    case 7:
        return "Authorship";
    case 8:
        return "Staking";
    case 9:
        return "Offences";
    case 10:
        return "Session";
    case 11:
        return "Finalitytracker";
    case 12:
        return "Grandpa";
    case 13:
        return "Imonline";
    case 14:
        return "Authoritydiscovery";
    case 15:
        return "Randomnesscollectiveflip";
    case 17:
        return "Sudo";
    case 18:
        return "Multisig";
    case 20:
        return "Contracts";
    case 21:
        return "Treasury";
    case 22:
        return "Polymeshcommittee";
    case 23:
        return "Committeemembership";
    case 24:
        return "Pips";
    case 25:
        return "Technicalcommittee";
    case 26:
        return "Technicalcommitteemembership";
    case 27:
        return "Upgradecommittee";
    case 28:
        return "Upgradecommitteemembership";
    case 29:
        return "Asset";
    case 31:
        return "Bridge";
    case 32:
        return "Compliancemanager";
    case 36:
        return "Settlement";
    case 37:
        return "Sto";
    case 38:
        return "Cddserviceproviders";
    case 39:
        return "Statistics";
    case 40:
        return "Protocolfee";
    case 41:
        return "Utility";
    case 42:
        return "Portfolio";
    case 43:
        return "Confidential";
    case 45:
        return "Scheduler";
    case 46:
        return "Corporateaction";
    case 47:
        return "Corporateballot";
    case 48:
        return "Capitaldistribution";
    case 49:
        return "Checkpoint";
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V5(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        return "Fill block";
    case 1: /* module 0 call 1 */
        return "Remark";
    case 2: /* module 0 call 2 */
        return "Set heap pages";
    case 3: /* module 0 call 3 */
        return "Set code";
    case 4: /* module 0 call 4 */
        return "Set code without checks";
    case 5: /* module 0 call 5 */
        return "Set changes trie config";
    case 6: /* module 0 call 6 */
        return "Set storage";
    case 7: /* module 0 call 7 */
        return "Kill storage";
    case 8: /* module 0 call 8 */
        return "Kill prefix";
    case 9: /* module 0 call 9 */
        return "Suicide";
    case 256: /* module 1 call 0 */
        return "Report equivocation";
    case 257: /* module 1 call 1 */
        return "Report equivocation unsigned";
    case 512: /* module 2 call 0 */
        return "Set";
    case 768: /* module 3 call 0 */
        return "Claim";
    case 769: /* module 3 call 1 */
        return "Transfer";
    case 770: /* module 3 call 2 */
        return "Free";
    case 771: /* module 3 call 3 */
        return "Force transfer";
    case 772: /* module 3 call 4 */
        return "Freeze";
    case 1024: /* module 4 call 0 */
        return "Transfer";
    case 1025: /* module 4 call 1 */
        return "Transfer with memo";
    case 1026: /* module 4 call 2 */
        return "Deposit block reward reserve balance";
    case 1027: /* module 4 call 3 */
        return "Set balance";
    case 1028: /* module 4 call 4 */
        return "Force transfer";
    case 1029: /* module 4 call 5 */
        return "Burn account balance";
    case 1536: /* module 6 call 0 */
        return "Register did";
    case 1537: /* module 6 call 1 */
        return "Cdd register did";
    case 1538: /* module 6 call 2 */
        return "Mock cdd register did";
    case 1539: /* module 6 call 3 */
        return "Invalidate cdd claims";
    case 1540: /* module 6 call 4 */
        return "Remove secondary keys";
    case 1541: /* module 6 call 5 */
        return "Accept primary key";
    case 1542: /* module 6 call 6 */
        return "Change cdd requirement for mk rotation";
    case 1543: /* module 6 call 7 */
        return "Join identity as key";
    case 1544: /* module 6 call 8 */
        return "Join identity as identity";
    case 1545: /* module 6 call 9 */
        return "Leave identity as key";
    case 1546: /* module 6 call 10 */
        return "Leave identity as identity";
    case 1547: /* module 6 call 11 */
        return "Add claim";
    case 1548: /* module 6 call 12 */
        return "Forwarded call";
    case 1549: /* module 6 call 13 */
        return "Revoke claim";
    case 1550: /* module 6 call 14 */
        return "Set permission to signer";
    case 1551: /* module 6 call 15 */
        return "Legacy set permission to signer";
    case 1552: /* module 6 call 16 */
        return "Freeze secondary keys";
    case 1553: /* module 6 call 17 */
        return "Unfreeze secondary keys";
    case 1554: /* module 6 call 18 */
        return "Get my did";
    case 1555: /* module 6 call 19 */
        return "Get cdd of";
    case 1556: /* module 6 call 20 */
        return "Add authorization";
    case 1557: /* module 6 call 21 */
        return "Remove authorization";
    case 1558: /* module 6 call 22 */
        return "Accept authorization";
    case 1559: /* module 6 call 23 */
        return "Add secondary keys with authorization";
    case 1560: /* module 6 call 24 */
        return "Revoke offchain authorization";
    case 1561: /* module 6 call 25 */
        return "Add investor uniqueness claim";
    case 1562: /* module 6 call 26 */
        return "Gc add cdd claim";
    case 1563: /* module 6 call 27 */
        return "Gc revoke cdd claim";
    case 1792: /* module 7 call 0 */
        return "Set uncles";
    case 2048: /* module 8 call 0 */
        return "Bond";
    case 2049: /* module 8 call 1 */
        return "Bond extra";
    case 2050: /* module 8 call 2 */
        return "Unbond";
    case 2051: /* module 8 call 3 */
        return "Withdraw Unbonded";
    case 2052: /* module 8 call 4 */
        return "Validate";
    case 2053: /* module 8 call 5 */
        return "Nominate";
    case 2054: /* module 8 call 6 */
        return "Chill";
    case 2055: /* module 8 call 7 */
        return "Set payee";
    case 2056: /* module 8 call 8 */
        return "Set controller";
    case 2057: /* module 8 call 9 */
        return "Set validator count";
    case 2058: /* module 8 call 10 */
        return "Increase validator count";
    case 2059: /* module 8 call 11 */
        return "Scale validator count";
    case 2060: /* module 8 call 12 */
        return "Add permissioned validator";
    case 2061: /* module 8 call 13 */
        return "Remove permissioned validator";
    case 2062: /* module 8 call 14 */
        return "Validate cdd expiry nominators";
    case 2063: /* module 8 call 15 */
        return "Set commission cap";
    case 2064: /* module 8 call 16 */
        return "Set min bond threshold";
    case 2065: /* module 8 call 17 */
        return "Force no eras";
    case 2066: /* module 8 call 18 */
        return "Force new era";
    case 2067: /* module 8 call 19 */
        return "Set invulnerables";
    case 2068: /* module 8 call 20 */
        return "Force unstake";
    case 2069: /* module 8 call 21 */
        return "Force new era always";
    case 2070: /* module 8 call 22 */
        return "Cancel deferred slash";
    case 2071: /* module 8 call 23 */
        return "Payout stakers";
    case 2072: /* module 8 call 24 */
        return "Rebond";
    case 2073: /* module 8 call 25 */
        return "Set history depth";
    case 2074: /* module 8 call 26 */
        return "Reap stash";
    case 2075: /* module 8 call 27 */
        return "Submit election solution";
    case 2076: /* module 8 call 28 */
        return "Submit election solution unsigned";
    case 2077: /* module 8 call 29 */
        return "Payout stakers by system";
    case 2078: /* module 8 call 30 */
        return "Change slashing allowed for";
    case 2079: /* module 8 call 31 */
        return "Update permissioned validator intended count";
    case 2560: /* module 10 call 0 */
        return "Set keys";
    case 2561: /* module 10 call 1 */
        return "Purge keys";
    case 2816: /* module 11 call 0 */
        return "Final hint";
    case 3072: /* module 12 call 0 */
        return "Report equivocation";
    case 3073: /* module 12 call 1 */
        return "Report equivocation unsigned";
    case 3074: /* module 12 call 2 */
        return "Note stalled";
    case 3328: /* module 13 call 0 */
        return "Heartbeat";
    case 3329: /* module 13 call 1 */
        return "Set slashing params";
    case 4352: /* module 17 call 0 */
        return "Sudo";
    case 4353: /* module 17 call 1 */
        return "Sudo unchecked weight";
    case 4354: /* module 17 call 2 */
        return "Set key";
    case 4355: /* module 17 call 3 */
        return "Sudo as";
    case 4608: /* module 18 call 0 */
        return "Create multisig";
    case 4609: /* module 18 call 1 */
        return "Create or approve proposal as identity";
    case 4610: /* module 18 call 2 */
        return "Create or approve proposal as key";
    case 4611: /* module 18 call 3 */
        return "Create proposal as identity";
    case 4612: /* module 18 call 4 */
        return "Create proposal as key";
    case 4613: /* module 18 call 5 */
        return "Approve as identity";
    case 4614: /* module 18 call 6 */
        return "Approve as key";
    case 4615: /* module 18 call 7 */
        return "Reject as identity";
    case 4616: /* module 18 call 8 */
        return "Reject as key";
    case 4617: /* module 18 call 9 */
        return "Accept multisig signer as identity";
    case 4618: /* module 18 call 10 */
        return "Accept multisig signer as key";
    case 4619: /* module 18 call 11 */
        return "Add multisig signer";
    case 4620: /* module 18 call 12 */
        return "Remove multisig signer";
    case 4621: /* module 18 call 13 */
        return "Add multisig signers via creator";
    case 4622: /* module 18 call 14 */
        return "Remove multisig signers via creator";
    case 4623: /* module 18 call 15 */
        return "Change sigs required";
    case 4624: /* module 18 call 16 */
        return "Make multisig signer";
    case 4625: /* module 18 call 17 */
        return "Make multisig primary";
    case 4626: /* module 18 call 18 */
        return "Execute scheduled proposal";
    case 5120: /* module 20 call 0 */
        return "Update schedule";
    case 5121: /* module 20 call 1 */
        return "Put code";
    case 5122: /* module 20 call 2 */
        return "Call";
    case 5123: /* module 20 call 3 */
        return "Instantiate";
    case 5124: /* module 20 call 4 */
        return "Freeze instantiation";
    case 5125: /* module 20 call 5 */
        return "Unfreeze instantiation";
    case 5126: /* module 20 call 6 */
        return "Transfer template ownership";
    case 5127: /* module 20 call 7 */
        return "Change template fees";
    case 5128: /* module 20 call 8 */
        return "Change template meta url";
    case 5376: /* module 21 call 0 */
        return "Disbursement";
    case 5377: /* module 21 call 1 */
        return "Reimbursement";
    case 5632: /* module 22 call 0 */
        return "Set vote threshold";
    case 5633: /* module 22 call 1 */
        return "Set release coordinator";
    case 5634: /* module 22 call 2 */
        return "Set expires after";
    case 5635: /* module 22 call 3 */
        return "Vote or propose";
    case 5636: /* module 22 call 4 */
        return "Vote";
    case 5888: /* module 23 call 0 */
        return "Set active members limit";
    case 5889: /* module 23 call 1 */
        return "Disable member";
    case 5890: /* module 23 call 2 */
        return "Add member";
    case 5891: /* module 23 call 3 */
        return "Remove member";
    case 5892: /* module 23 call 4 */
        return "Swap member";
    case 5893: /* module 23 call 5 */
        return "Reset members";
    case 5894: /* module 23 call 6 */
        return "Abdicate membership";
    case 6144: /* module 24 call 0 */
        return "Set prune historical pips";
    case 6145: /* module 24 call 1 */
        return "Set min proposal deposit";
    case 6146: /* module 24 call 2 */
        return "Set default enactment period";
    case 6147: /* module 24 call 3 */
        return "Set pending pip expiry";
    case 6148: /* module 24 call 4 */
        return "Set max pip skip count";
    case 6149: /* module 24 call 5 */
        return "Set active pip limit";
    case 6150: /* module 24 call 6 */
        return "Propose";
    case 6151: /* module 24 call 7 */
        return "Vote";
    case 6152: /* module 24 call 8 */
        return "Approve committee proposal";
    case 6153: /* module 24 call 9 */
        return "Reject proposal";
    case 6154: /* module 24 call 10 */
        return "Prune proposal";
    case 6155: /* module 24 call 11 */
        return "Reschedule execution";
    case 6156: /* module 24 call 12 */
        return "Clear snapshot";
    case 6157: /* module 24 call 13 */
        return "Snapshot";
    case 6158: /* module 24 call 14 */
        return "Enact snapshot results";
    case 6159: /* module 24 call 15 */
        return "Execute scheduled pip";
    case 6160: /* module 24 call 16 */
        return "Expire scheduled pip";
    case 6400: /* module 25 call 0 */
        return "Set vote threshold";
    case 6401: /* module 25 call 1 */
        return "Set release coordinator";
    case 6402: /* module 25 call 2 */
        return "Set expires after";
    case 6403: /* module 25 call 3 */
        return "Vote or propose";
    case 6404: /* module 25 call 4 */
        return "Vote";
    case 6656: /* module 26 call 0 */
        return "Set active members limit";
    case 6657: /* module 26 call 1 */
        return "Disable member";
    case 6658: /* module 26 call 2 */
        return "Add member";
    case 6659: /* module 26 call 3 */
        return "Remove member";
    case 6660: /* module 26 call 4 */
        return "Swap member";
    case 6661: /* module 26 call 5 */
        return "Reset members";
    case 6662: /* module 26 call 6 */
        return "Abdicate membership";
    case 6912: /* module 27 call 0 */
        return "Set vote threshold";
    case 6913: /* module 27 call 1 */
        return "Set release coordinator";
    case 6914: /* module 27 call 2 */
        return "Set expires after";
    case 6915: /* module 27 call 3 */
        return "Vote or propose";
    case 6916: /* module 27 call 4 */
        return "Vote";
    case 7168: /* module 28 call 0 */
        return "Set active members limit";
    case 7169: /* module 28 call 1 */
        return "Disable member";
    case 7170: /* module 28 call 2 */
        return "Add member";
    case 7171: /* module 28 call 3 */
        return "Remove member";
    case 7172: /* module 28 call 4 */
        return "Swap member";
    case 7173: /* module 28 call 5 */
        return "Reset members";
    case 7174: /* module 28 call 6 */
        return "Abdicate membership";
    case 7424: /* module 29 call 0 */
        return "Register ticker";
    case 7425: /* module 29 call 1 */
        return "Accept ticker transfer";
    case 7426: /* module 29 call 2 */
        return "Accept primary issuance agent transfer";
    case 7427: /* module 29 call 3 */
        return "Accept asset ownership transfer";
    case 7428: /* module 29 call 4 */
        return "Create asset";
    case 7429: /* module 29 call 5 */
        return "Freeze";
    case 7430: /* module 29 call 6 */
        return "Unfreeze";
    case 7431: /* module 29 call 7 */
        return "Rename asset";
    case 7432: /* module 29 call 8 */
        return "Issue";
    case 7433: /* module 29 call 9 */
        return "Redeem";
    case 7434: /* module 29 call 10 */
        return "Make divisible";
    case 7435: /* module 29 call 11 */
        return "Add documents";
    case 7436: /* module 29 call 12 */
        return "Remove documents";
    case 7437: /* module 29 call 13 */
        return "Set funding round";
    case 7438: /* module 29 call 14 */
        return "Update identifiers";
    case 7439: /* module 29 call 15 */
        return "Add extension";
    case 7440: /* module 29 call 16 */
        return "Archive extension";
    case 7441: /* module 29 call 17 */
        return "Unarchive extension";
    case 7442: /* module 29 call 18 */
        return "Remove primary issuance agent";
    case 7443: /* module 29 call 19 */
        return "Remove smart extension";
    case 7444: /* module 29 call 20 */
        return "Claim classic ticker";
    case 7445: /* module 29 call 21 */
        return "Reserve classic ticker";
    case 7936: /* module 31 call 0 */
        return "Change controller";
    case 7937: /* module 31 call 1 */
        return "Change admin";
    case 7938: /* module 31 call 2 */
        return "Change timelock";
    case 7939: /* module 31 call 3 */
        return "Freeze";
    case 7940: /* module 31 call 4 */
        return "Unfreeze";
    case 7941: /* module 31 call 5 */
        return "Change bridge limit";
    case 7942: /* module 31 call 6 */
        return "Change bridge exempted";
    case 7943: /* module 31 call 7 */
        return "Force handle bridge tx";
    case 7944: /* module 31 call 8 */
        return "Batch propose bridge tx";
    case 7945: /* module 31 call 9 */
        return "Propose bridge tx";
    case 7946: /* module 31 call 10 */
        return "Handle bridge tx";
    case 7947: /* module 31 call 11 */
        return "Freeze txs";
    case 7948: /* module 31 call 12 */
        return "Unfreeze txs";
    case 7949: /* module 31 call 13 */
        return "Handle scheduled bridge tx";
    case 8192: /* module 32 call 0 */
        return "Add compliance requirement";
    case 8193: /* module 32 call 1 */
        return "Remove compliance requirement";
    case 8194: /* module 32 call 2 */
        return "Replace asset compliance";
    case 8195: /* module 32 call 3 */
        return "Reset asset compliance";
    case 8196: /* module 32 call 4 */
        return "Pause asset compliance";
    case 8197: /* module 32 call 5 */
        return "Resume asset compliance";
    case 8198: /* module 32 call 6 */
        return "Add default trusted claim issuer";
    case 8199: /* module 32 call 7 */
        return "Remove default trusted claim issuer";
    case 8200: /* module 32 call 8 */
        return "Change compliance requirement";
    case 9216: /* module 36 call 0 */
        return "Create venue";
    case 9217: /* module 36 call 1 */
        return "Update venue";
    case 9218: /* module 36 call 2 */
        return "Add instruction";
    case 9219: /* module 36 call 3 */
        return "Add and affirm instruction";
    case 9220: /* module 36 call 4 */
        return "Affirm instruction";
    case 9221: /* module 36 call 5 */
        return "Withdraw affirmation";
    case 9222: /* module 36 call 6 */
        return "Reject instruction";
    case 9223: /* module 36 call 7 */
        return "Affirm with receipts";
    case 9224: /* module 36 call 8 */
        return "Claim receipt";
    case 9225: /* module 36 call 9 */
        return "Unclaim receipt";
    case 9226: /* module 36 call 10 */
        return "Set venue filtering";
    case 9227: /* module 36 call 11 */
        return "Allow venues";
    case 9228: /* module 36 call 12 */
        return "Disallow venues";
    case 9229: /* module 36 call 13 */
        return "Execute scheduled instruction";
    case 9472: /* module 37 call 0 */
        return "Create fundraiser";
    case 9473: /* module 37 call 1 */
        return "Invest";
    case 9474: /* module 37 call 2 */
        return "Freeze fundraiser";
    case 9475: /* module 37 call 3 */
        return "Unfreeze fundraiser";
    case 9476: /* module 37 call 4 */
        return "Modify fundraiser window";
    case 9477: /* module 37 call 5 */
        return "Stop";
    case 9728: /* module 38 call 0 */
        return "Set active members limit";
    case 9729: /* module 38 call 1 */
        return "Disable member";
    case 9730: /* module 38 call 2 */
        return "Add member";
    case 9731: /* module 38 call 3 */
        return "Remove member";
    case 9732: /* module 38 call 4 */
        return "Swap member";
    case 9733: /* module 38 call 5 */
        return "Reset members";
    case 9734: /* module 38 call 6 */
        return "Abdicate membership";
    case 9984: /* module 39 call 0 */
        return "Add transfer manager";
    case 9985: /* module 39 call 1 */
        return "Remove transfer manager";
    case 9986: /* module 39 call 2 */
        return "Add exempted entities";
    case 9987: /* module 39 call 3 */
        return "Remove exempted entities";
    case 10240: /* module 40 call 0 */
        return "Change coefficient";
    case 10241: /* module 40 call 1 */
        return "Change base fee";
    case 10496: /* module 41 call 0 */
        return "Batch";
    case 10497: /* module 41 call 1 */
        return "Batch atomic";
    case 10498: /* module 41 call 2 */
        return "Batch optimistic";
    case 10499: /* module 41 call 3 */
        return "Relay tx";
    case 10752: /* module 42 call 0 */
        return "Create portfolio";
    case 10753: /* module 42 call 1 */
        return "Delete portfolio";
    case 10754: /* module 42 call 2 */
        return "Move portfolio funds";
    case 10755: /* module 42 call 3 */
        return "Rename portfolio";
    case 11008: /* module 43 call 0 */
        return "Add range proof";
    case 11009: /* module 43 call 1 */
        return "Add verify range proof";
    case 11520: /* module 45 call 0 */
        return "Schedule";
    case 11521: /* module 45 call 1 */
        return "Cancel";
    case 11522: /* module 45 call 2 */
        return "Schedule named";
    case 11523: /* module 45 call 3 */
        return "Cancel named";
    case 11524: /* module 45 call 4 */
        return "Schedule after";
    case 11525: /* module 45 call 5 */
        return "Schedule named after";
    case 11776: /* module 46 call 0 */
        return "Set max details length";
    case 11777: /* module 46 call 1 */
        return "Reset caa";
    case 11778: /* module 46 call 2 */
        return "Set default targets";
    case 11779: /* module 46 call 3 */
        return "Set default withholding tax";
    case 11780: /* module 46 call 4 */
        return "Set did withholding tax";
    case 11781: /* module 46 call 5 */
        return "Initiate corporate action";
    case 11782: /* module 46 call 6 */
        return "Link ca doc";
    case 11783: /* module 46 call 7 */
        return "Remove ca";
    case 11784: /* module 46 call 8 */
        return "Change record date";
    case 12032: /* module 47 call 0 */
        return "Attach ballot";
    case 12033: /* module 47 call 1 */
        return "Vote";
    case 12034: /* module 47 call 2 */
        return "Change end";
    case 12035: /* module 47 call 3 */
        return "Change meta";
    case 12036: /* module 47 call 4 */
        return "Change rcv";
    case 12037: /* module 47 call 5 */
        return "Remove ballot";
    case 12288: /* module 48 call 0 */
        return "Distribute";
    case 12289: /* module 48 call 1 */
        return "Claim";
    case 12290: /* module 48 call 2 */
        return "Push benefit";
    case 12291: /* module 48 call 3 */
        return "Reclaim";
    case 12292: /* module 48 call 4 */
        return "Remove distribution";
    case 12544: /* module 49 call 0 */
        return "Create checkpoint";
    case 12545: /* module 49 call 1 */
        return "Set schedules max complexity";
    case 12546: /* module 49 call 2 */
        return "Create schedule";
    case 12547: /* module 49 call 3 */
        return "Remove schedule";
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V5(uint8_t moduleIdx, uint8_t callIdx, pd_Method_V5_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 4: /* module 0 call 4 */
        return 1;
    case 5: /* module 0 call 5 */
        return 1;
    case 6: /* module 0 call 6 */
        return 1;
    case 7: /* module 0 call 7 */
        return 1;
    case 8: /* module 0 call 8 */
        return 2;
    case 9: /* module 0 call 9 */
        return 0;
    case 256: /* module 1 call 0 */
        return 2;
    case 257: /* module 1 call 1 */
        return 2;
    case 512: /* module 2 call 0 */
        return 1;
    case 768: /* module 3 call 0 */
        return 1;
    case 769: /* module 3 call 1 */
        return 2;
    case 770: /* module 3 call 2 */
        return 1;
    case 771: /* module 3 call 3 */
        return 3;
    case 772: /* module 3 call 4 */
        return 1;
    case 1024: /* module 4 call 0 */
        return 2;
    case 1025: /* module 4 call 1 */
        return 3;
    case 1026: /* module 4 call 2 */
        return 1;
    case 1027: /* module 4 call 3 */
        return 3;
    case 1028: /* module 4 call 4 */
        return 3;
    case 1029: /* module 4 call 5 */
        return 1;
    case 1536: /* module 6 call 0 */
        return 2;
    case 1537: /* module 6 call 1 */
        return 2;
    case 1538: /* module 6 call 2 */
        return 1;
    case 1539: /* module 6 call 3 */
        return 3;
    case 1540: /* module 6 call 4 */
        return 1;
    case 1541: /* module 6 call 5 */
        return 2;
    case 1542: /* module 6 call 6 */
        return 1;
    case 1543: /* module 6 call 7 */
        return 1;
    case 1544: /* module 6 call 8 */
        return 1;
    case 1545: /* module 6 call 9 */
        return 0;
    case 1546: /* module 6 call 10 */
        return 1;
    case 1547: /* module 6 call 11 */
        return 3;
    case 1548: /* module 6 call 12 */
        return 2;
    case 1549: /* module 6 call 13 */
        return 2;
    case 1550: /* module 6 call 14 */
        return 2;
    case 1551: /* module 6 call 15 */
        return 2;
    case 1552: /* module 6 call 16 */
        return 0;
    case 1553: /* module 6 call 17 */
        return 0;
    case 1554: /* module 6 call 18 */
        return 0;
    case 1555: /* module 6 call 19 */
        return 1;
    case 1556: /* module 6 call 20 */
        return 3;
    case 1557: /* module 6 call 21 */
        return 3;
    case 1558: /* module 6 call 22 */
        return 1;
    case 1559: /* module 6 call 23 */
        return 2;
    case 1560: /* module 6 call 24 */
        return 2;
    case 1561: /* module 6 call 25 */
        return 4;
    case 1562: /* module 6 call 26 */
        return 2;
    case 1563: /* module 6 call 27 */
        return 1;
    case 1792: /* module 7 call 0 */
        return 1;
    case 2048: /* module 8 call 0 */
        return 3;
    case 2049: /* module 8 call 1 */
        return 1;
    case 2050: /* module 8 call 2 */
        return 1;
    case 2051: /* module 8 call 3 */
        return 1;
    case 2052: /* module 8 call 4 */
        return 1;
    case 2053: /* module 8 call 5 */
        return 1;
    case 2054: /* module 8 call 6 */
        return 0;
    case 2055: /* module 8 call 7 */
        return 1;
    case 2056: /* module 8 call 8 */
        return 1;
    case 2057: /* module 8 call 9 */
        return 1;
    case 2058: /* module 8 call 10 */
        return 1;
    case 2059: /* module 8 call 11 */
        return 1;
    case 2060: /* module 8 call 12 */
        return 2;
    case 2061: /* module 8 call 13 */
        return 1;
    case 2062: /* module 8 call 14 */
        return 1;
    case 2063: /* module 8 call 15 */
        return 1;
    case 2064: /* module 8 call 16 */
        return 1;
    case 2065: /* module 8 call 17 */
        return 0;
    case 2066: /* module 8 call 18 */
        return 0;
    case 2067: /* module 8 call 19 */
        return 1;
    case 2068: /* module 8 call 20 */
        return 2;
    case 2069: /* module 8 call 21 */
        return 0;
    case 2070: /* module 8 call 22 */
        return 2;
    case 2071: /* module 8 call 23 */
        return 2;
    case 2072: /* module 8 call 24 */
        return 1;
    case 2073: /* module 8 call 25 */
        return 2;
    case 2074: /* module 8 call 26 */
        return 2;
    case 2075: /* module 8 call 27 */
        return 5;
    case 2076: /* module 8 call 28 */
        return 5;
    case 2077: /* module 8 call 29 */
        return 2;
    case 2078: /* module 8 call 30 */
        return 1;
    case 2079: /* module 8 call 31 */
        return 2;
    case 2560: /* module 10 call 0 */
        return 2;
    case 2561: /* module 10 call 1 */
        return 0;
    case 2816: /* module 11 call 0 */
        return 1;
    case 3072: /* module 12 call 0 */
        return 2;
    case 3073: /* module 12 call 1 */
        return 2;
    case 3074: /* module 12 call 2 */
        return 2;
    case 3328: /* module 13 call 0 */
        return 2;
    case 3329: /* module 13 call 1 */
        return 1;
    case 4352: /* module 17 call 0 */
        return 1;
    case 4353: /* module 17 call 1 */
        return 2;
    case 4354: /* module 17 call 2 */
        return 1;
    case 4355: /* module 17 call 3 */
        return 2;
    case 4608: /* module 18 call 0 */
        return 2;
    case 4609: /* module 18 call 1 */
        return 4;
    case 4610: /* module 18 call 2 */
        return 4;
    case 4611: /* module 18 call 3 */
        return 4;
    case 4612: /* module 18 call 4 */
        return 4;
    case 4613: /* module 18 call 5 */
        return 2;
    case 4614: /* module 18 call 6 */
        return 2;
    case 4615: /* module 18 call 7 */
        return 2;
    case 4616: /* module 18 call 8 */
        return 2;
    case 4617: /* module 18 call 9 */
        return 1;
    case 4618: /* module 18 call 10 */
        return 1;
    case 4619: /* module 18 call 11 */
        return 1;
    case 4620: /* module 18 call 12 */
        return 1;
    case 4621: /* module 18 call 13 */
        return 2;
    case 4622: /* module 18 call 14 */
        return 2;
    case 4623: /* module 18 call 15 */
        return 1;
    case 4624: /* module 18 call 16 */
        return 1;
    case 4625: /* module 18 call 17 */
        return 2;
    case 4626: /* module 18 call 18 */
        return 4;
    case 5120: /* module 20 call 0 */
        return 1;
    case 5121: /* module 20 call 1 */
        return 3;
    case 5122: /* module 20 call 2 */
        return 4;
    case 5123: /* module 20 call 3 */
        return 5;
    case 5124: /* module 20 call 4 */
        return 1;
    case 5125: /* module 20 call 5 */
        return 1;
    case 5126: /* module 20 call 6 */
        return 2;
    case 5127: /* module 20 call 7 */
        return 3;
    case 5128: /* module 20 call 8 */
        return 2;
    case 5376: /* module 21 call 0 */
        return 1;
    case 5377: /* module 21 call 1 */
        return 1;
    case 5632: /* module 22 call 0 */
        return 2;
    case 5633: /* module 22 call 1 */
        return 1;
    case 5634: /* module 22 call 2 */
        return 1;
    case 5635: /* module 22 call 3 */
        return 2;
    case 5636: /* module 22 call 4 */
        return 3;
    case 5888: /* module 23 call 0 */
        return 1;
    case 5889: /* module 23 call 1 */
        return 3;
    case 5890: /* module 23 call 2 */
        return 1;
    case 5891: /* module 23 call 3 */
        return 1;
    case 5892: /* module 23 call 4 */
        return 2;
    case 5893: /* module 23 call 5 */
        return 1;
    case 5894: /* module 23 call 6 */
        return 0;
    case 6144: /* module 24 call 0 */
        return 1;
    case 6145: /* module 24 call 1 */
        return 1;
    case 6146: /* module 24 call 2 */
        return 1;
    case 6147: /* module 24 call 3 */
        return 1;
    case 6148: /* module 24 call 4 */
        return 1;
    case 6149: /* module 24 call 5 */
        return 1;
    case 6150: /* module 24 call 6 */
        return 4;
    case 6151: /* module 24 call 7 */
        return 3;
    case 6152: /* module 24 call 8 */
        return 1;
    case 6153: /* module 24 call 9 */
        return 1;
    case 6154: /* module 24 call 10 */
        return 1;
    case 6155: /* module 24 call 11 */
        return 2;
    case 6156: /* module 24 call 12 */
        return 0;
    case 6157: /* module 24 call 13 */
        return 0;
    case 6158: /* module 24 call 14 */
        return 1;
    case 6159: /* module 24 call 15 */
        return 1;
    case 6160: /* module 24 call 16 */
        return 2;
    case 6400: /* module 25 call 0 */
        return 2;
    case 6401: /* module 25 call 1 */
        return 1;
    case 6402: /* module 25 call 2 */
        return 1;
    case 6403: /* module 25 call 3 */
        return 2;
    case 6404: /* module 25 call 4 */
        return 3;
    case 6656: /* module 26 call 0 */
        return 1;
    case 6657: /* module 26 call 1 */
        return 3;
    case 6658: /* module 26 call 2 */
        return 1;
    case 6659: /* module 26 call 3 */
        return 1;
    case 6660: /* module 26 call 4 */
        return 2;
    case 6661: /* module 26 call 5 */
        return 1;
    case 6662: /* module 26 call 6 */
        return 0;
    case 6912: /* module 27 call 0 */
        return 2;
    case 6913: /* module 27 call 1 */
        return 1;
    case 6914: /* module 27 call 2 */
        return 1;
    case 6915: /* module 27 call 3 */
        return 2;
    case 6916: /* module 27 call 4 */
        return 3;
    case 7168: /* module 28 call 0 */
        return 1;
    case 7169: /* module 28 call 1 */
        return 3;
    case 7170: /* module 28 call 2 */
        return 1;
    case 7171: /* module 28 call 3 */
        return 1;
    case 7172: /* module 28 call 4 */
        return 2;
    case 7173: /* module 28 call 5 */
        return 1;
    case 7174: /* module 28 call 6 */
        return 0;
    case 7424: /* module 29 call 0 */
        return 1;
    case 7425: /* module 29 call 1 */
        return 1;
    case 7426: /* module 29 call 2 */
        return 1;
    case 7427: /* module 29 call 3 */
        return 1;
    case 7428: /* module 29 call 4 */
        return 7;
    case 7429: /* module 29 call 5 */
        return 1;
    case 7430: /* module 29 call 6 */
        return 1;
    case 7431: /* module 29 call 7 */
        return 2;
    case 7432: /* module 29 call 8 */
        return 2;
    case 7433: /* module 29 call 9 */
        return 2;
    case 7434: /* module 29 call 10 */
        return 1;
    case 7435: /* module 29 call 11 */
        return 2;
    case 7436: /* module 29 call 12 */
        return 2;
    case 7437: /* module 29 call 13 */
        return 2;
    case 7438: /* module 29 call 14 */
        return 2;
    case 7439: /* module 29 call 15 */
        return 2;
    case 7440: /* module 29 call 16 */
        return 2;
    case 7441: /* module 29 call 17 */
        return 2;
    case 7442: /* module 29 call 18 */
        return 1;
    case 7443: /* module 29 call 19 */
        return 2;
    case 7444: /* module 29 call 20 */
        return 2;
    case 7445: /* module 29 call 21 */
        return 3;
    case 7936: /* module 31 call 0 */
        return 1;
    case 7937: /* module 31 call 1 */
        return 1;
    case 7938: /* module 31 call 2 */
        return 1;
    case 7939: /* module 31 call 3 */
        return 0;
    case 7940: /* module 31 call 4 */
        return 0;
    case 7941: /* module 31 call 5 */
        return 2;
    case 7942: /* module 31 call 6 */
        return 1;
    case 7943: /* module 31 call 7 */
        return 1;
    case 7944: /* module 31 call 8 */
        return 1;
    case 7945: /* module 31 call 9 */
        return 1;
    case 7946: /* module 31 call 10 */
        return 1;
    case 7947: /* module 31 call 11 */
        return 1;
    case 7948: /* module 31 call 12 */
        return 1;
    case 7949: /* module 31 call 13 */
        return 1;
    case 8192: /* module 32 call 0 */
        return 3;
    case 8193: /* module 32 call 1 */
        return 2;
    case 8194: /* module 32 call 2 */
        return 2;
    case 8195: /* module 32 call 3 */
        return 1;
    case 8196: /* module 32 call 4 */
        return 1;
    case 8197: /* module 32 call 5 */
        return 1;
    case 8198: /* module 32 call 6 */
        return 2;
    case 8199: /* module 32 call 7 */
        return 2;
    case 8200: /* module 32 call 8 */
        return 2;
    case 9216: /* module 36 call 0 */
        return 3;
    case 9217: /* module 36 call 1 */
        return 3;
    case 9218: /* module 36 call 2 */
        return 5;
    case 9219: /* module 36 call 3 */
        return 6;
    case 9220: /* module 36 call 4 */
        return 3;
    case 9221: /* module 36 call 5 */
        return 3;
    case 9222: /* module 36 call 6 */
        return 3;
    case 9223: /* module 36 call 7 */
        return 4;
    case 9224: /* module 36 call 8 */
        return 2;
    case 9225: /* module 36 call 9 */
        return 2;
    case 9226: /* module 36 call 10 */
        return 2;
    case 9227: /* module 36 call 11 */
        return 2;
    case 9228: /* module 36 call 12 */
        return 2;
    case 9229: /* module 36 call 13 */
        return 2;
    case 9472: /* module 37 call 0 */
        return 10;
    case 9473: /* module 37 call 1 */
        return 7;
    case 9474: /* module 37 call 2 */
        return 2;
    case 9475: /* module 37 call 3 */
        return 2;
    case 9476: /* module 37 call 4 */
        return 4;
    case 9477: /* module 37 call 5 */
        return 2;
    case 9728: /* module 38 call 0 */
        return 1;
    case 9729: /* module 38 call 1 */
        return 3;
    case 9730: /* module 38 call 2 */
        return 1;
    case 9731: /* module 38 call 3 */
        return 1;
    case 9732: /* module 38 call 4 */
        return 2;
    case 9733: /* module 38 call 5 */
        return 1;
    case 9734: /* module 38 call 6 */
        return 0;
    case 9984: /* module 39 call 0 */
        return 2;
    case 9985: /* module 39 call 1 */
        return 2;
    case 9986: /* module 39 call 2 */
        return 3;
    case 9987: /* module 39 call 3 */
        return 3;
    case 10240: /* module 40 call 0 */
        return 1;
    case 10241: /* module 40 call 1 */
        return 2;
    case 10496: /* module 41 call 0 */
        return 1;
    case 10497: /* module 41 call 1 */
        return 1;
    case 10498: /* module 41 call 2 */
        return 1;
    case 10499: /* module 41 call 3 */
        return 3;
    case 10752: /* module 42 call 0 */
        return 1;
    case 10753: /* module 42 call 1 */
        return 1;
    case 10754: /* module 42 call 2 */
        return 3;
    case 10755: /* module 42 call 3 */
        return 2;
    case 11008: /* module 43 call 0 */
        return 3;
    case 11009: /* module 43 call 1 */
        return 3;
    case 11520: /* module 45 call 0 */
        return 4;
    case 11521: /* module 45 call 1 */
        return 2;
    case 11522: /* module 45 call 2 */
        return 5;
    case 11523: /* module 45 call 3 */
        return 1;
    case 11524: /* module 45 call 4 */
        return 4;
    case 11525: /* module 45 call 5 */
        return 5;
    case 11776: /* module 46 call 0 */
        return 1;
    case 11777: /* module 46 call 1 */
        return 1;
    case 11778: /* module 46 call 2 */
        return 2;
    case 11779: /* module 46 call 3 */
        return 2;
    case 11780: /* module 46 call 4 */
        return 3;
    case 11781: /* module 46 call 5 */
        return 8;
    case 11782: /* module 46 call 6 */
        return 2;
    case 11783: /* module 46 call 7 */
        return 1;
    case 11784: /* module 46 call 8 */
        return 2;
    case 12032: /* module 47 call 0 */
        return 4;
    case 12033: /* module 47 call 1 */
        return 2;
    case 12034: /* module 47 call 2 */
        return 2;
    case 12035: /* module 47 call 3 */
        return 2;
    case 12036: /* module 47 call 4 */
        return 2;
    case 12037: /* module 47 call 5 */
        return 1;
    case 12288: /* module 48 call 0 */
        return 6;
    case 12289: /* module 48 call 1 */
        return 1;
    case 12290: /* module 48 call 2 */
        return 2;
    case 12291: /* module 48 call 3 */
        return 1;
    case 12292: /* module 48 call 4 */
        return 1;
    case 12544: /* module 49 call 0 */
        return 1;
    case 12545: /* module 49 call 1 */
        return 1;
    case 12546: /* module 49 call 2 */
        return 2;
    case 12547: /* module 49 call 3 */
        return 2;
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V5(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return "Ratio";
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return "Remark";
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return "Pages";
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return "Code";
        default:
            return NULL;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0:
            return "Code";
        default:
            return NULL;
        }
    case 5: /* module 0 call 5 */
        switch (itemIdx) {
        case 0:
            return "Changes trie config";
        default:
            return NULL;
        }
    case 6: /* module 0 call 6 */
        switch (itemIdx) {
        case 0:
            return "Items";
        default:
            return NULL;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0:
            return "Keys";
        default:
            return NULL;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0:
            return "Prefix";
        case 1:
            return "Subkeys";
        default:
            return NULL;
        }
    case 9: /* module 0 call 9 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0:
            return "Equivocation proof";
        case 1:
            return "Key owner proof";
        default:
            return NULL;
        }
    case 257: /* module 1 call 1 */
        switch (itemIdx) {
        case 0:
            return "Equivocation proof";
        case 1:
            return "Key owner proof";
        default:
            return NULL;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0:
            return "Now";
        default:
            return NULL;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0:
            return "Index";
        default:
            return NULL;
        }
    case 769: /* module 3 call 1 */
        switch (itemIdx) {
        case 0:
            return "New";
        case 1:
            return "Index";
        default:
            return NULL;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0:
            return "Index";
        default:
            return NULL;
        }
    case 771: /* module 3 call 3 */
        switch (itemIdx) {
        case 0:
            return "New";
        case 1:
            return "Index";
        case 2:
            return "Freeze";
        default:
            return NULL;
        }
    case 772: /* module 3 call 4 */
        switch (itemIdx) {
        case 0:
            return "Index";
        default:
            return NULL;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0:
            return "Dest";
        case 1:
            return "Amount";
        default:
            return NULL;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0:
            return "Dest";
        case 1:
            return "Amount";
        case 2:
            return "Memo";
        default:
            return NULL;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0:
            return "Amount";
        default:
            return NULL;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0:
            return "Who";
        case 1:
            return "New free";
        case 2:
            return "New reserved";
        default:
            return NULL;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0:
            return "Source";
        case 1:
            return "Dest";
        case 2:
            return "Amount";
        default:
            return NULL;
        }
    case 1029: /* module 4 call 5 */
        switch (itemIdx) {
        case 0:
            return "Amount";
        default:
            return NULL;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0:
            return "Uid";
        case 1:
            return "Secondary keys";
        default:
            return NULL;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0:
            return "Target account";
        case 1:
            return "Secondary keys";
        default:
            return NULL;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0:
            return "Target account";
        default:
            return NULL;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0:
            return "Cdd";
        case 1:
            return "Disable from";
        case 2:
            return "Expiry";
        default:
            return NULL;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0:
            return "Signers to remove";
        default:
            return NULL;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0:
            return "Rotation auth id";
        case 1:
            return "Optional cdd auth id";
        default:
            return NULL;
        }
    case 1542: /* module 6 call 6 */
        switch (itemIdx) {
        case 0:
            return "Auth required";
        default:
            return NULL;
        }
    case 1543: /* module 6 call 7 */
        switch (itemIdx) {
        case 0:
            return "Auth id";
        default:
            return NULL;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0:
            return "Auth id";
        default:
            return NULL;
        }
    case 1545: /* module 6 call 9 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1546: /* module 6 call 10 */
        switch (itemIdx) {
        case 0:
            return "Did";
        default:
            return NULL;
        }
    case 1547: /* module 6 call 11 */
        switch (itemIdx) {
        case 0:
            return "Target";
        case 1:
            return "Claim";
        case 2:
            return "Expiry";
        default:
            return NULL;
        }
    case 1548: /* module 6 call 12 */
        switch (itemIdx) {
        case 0:
            return "Target did";
        case 1:
            return "Proposal";
        default:
            return NULL;
        }
    case 1549: /* module 6 call 13 */
        switch (itemIdx) {
        case 0:
            return "Target";
        case 1:
            return "Claim";
        default:
            return NULL;
        }
    case 1550: /* module 6 call 14 */
        switch (itemIdx) {
        case 0:
            return "Signer";
        case 1:
            return "Permissions";
        default:
            return NULL;
        }
    case 1551: /* module 6 call 15 */
        switch (itemIdx) {
        case 0:
            return "Signer";
        case 1:
            return "Permissions";
        default:
            return NULL;
        }
    case 1552: /* module 6 call 16 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1553: /* module 6 call 17 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1554: /* module 6 call 18 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1555: /* module 6 call 19 */
        switch (itemIdx) {
        case 0:
            return "Of";
        default:
            return NULL;
        }
    case 1556: /* module 6 call 20 */
        switch (itemIdx) {
        case 0:
            return "Target";
        case 1:
            return "Authorization data";
        case 2:
            return "Expiry";
        default:
            return NULL;
        }
    case 1557: /* module 6 call 21 */
        switch (itemIdx) {
        case 0:
            return "Target";
        case 1:
            return "Auth id";
        case 2:
            return "Auth issuer pays";
        default:
            return NULL;
        }
    case 1558: /* module 6 call 22 */
        switch (itemIdx) {
        case 0:
            return "Auth id";
        default:
            return NULL;
        }
    case 1559: /* module 6 call 23 */
        switch (itemIdx) {
        case 0:
            return "Additional keys";
        case 1:
            return "Expires at";
        default:
            return NULL;
        }
    case 1560: /* module 6 call 24 */
        switch (itemIdx) {
        case 0:
            return "Signer";
        case 1:
            return "Auth";
        default:
            return NULL;
        }
    case 1561: /* module 6 call 25 */
        switch (itemIdx) {
        case 0:
            return "Target";
        case 1:
            return "Claim";
        case 2:
            return "Proof";
        case 3:
            return "Expiry";
        default:
            return NULL;
        }
    case 1562: /* module 6 call 26 */
        switch (itemIdx) {
        case 0:
            return "Target";
        case 1:
            return "Expiry";
        default:
            return NULL;
        }
    case 1563: /* module 6 call 27 */
        switch (itemIdx) {
        case 0:
            return "Target";
        default:
            return NULL;
        }
    case 1792: /* module 7 call 0 */
        switch (itemIdx) {
        case 0:
            return "New uncles";
        default:
            return NULL;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0:
            return "Controller";
        case 1:
            return "Amount";
        case 2:
            return "Payee";
        default:
            return NULL;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        case 0:
            return "Amount";
        default:
            return NULL;
        }
    case 2050: /* module 8 call 2 */
        switch (itemIdx) {
        case 0:
            return "Amount";
        default:
            return NULL;
        }
    case 2051: /* module 8 call 3 */
        switch (itemIdx) {
        case 0:
            return "Num slashing spans";
        default:
            return NULL;
        }
    case 2052: /* module 8 call 4 */
        switch (itemIdx) {
        case 0:
            return "Prefs";
        default:
            return NULL;
        }
    case 2053: /* module 8 call 5 */
        switch (itemIdx) {
        case 0:
            return "Targets";
        default:
            return NULL;
        }
    case 2054: /* module 8 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2055: /* module 8 call 7 */
        switch (itemIdx) {
        case 0:
            return "Payee";
        default:
            return NULL;
        }
    case 2056: /* module 8 call 8 */
        switch (itemIdx) {
        case 0:
            return "Controller";
        default:
            return NULL;
        }
    case 2057: /* module 8 call 9 */
        switch (itemIdx) {
        case 0:
            return "New";
        default:
            return NULL;
        }
    case 2058: /* module 8 call 10 */
        switch (itemIdx) {
        case 0:
            return "Additional";
        default:
            return NULL;
        }
    case 2059: /* module 8 call 11 */
        switch (itemIdx) {
        case 0:
            return "Factor";
        default:
            return NULL;
        }
    case 2060: /* module 8 call 12 */
        switch (itemIdx) {
        case 0:
            return "Identity";
        case 1:
            return "Intended count";
        default:
            return NULL;
        }
    case 2061: /* module 8 call 13 */
        switch (itemIdx) {
        case 0:
            return "Identity";
        default:
            return NULL;
        }
    case 2062: /* module 8 call 14 */
        switch (itemIdx) {
        case 0:
            return "Targets";
        default:
            return NULL;
        }
    case 2063: /* module 8 call 15 */
        switch (itemIdx) {
        case 0:
            return "New cap";
        default:
            return NULL;
        }
    case 2064: /* module 8 call 16 */
        switch (itemIdx) {
        case 0:
            return "New value";
        default:
            return NULL;
        }
    case 2065: /* module 8 call 17 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2066: /* module 8 call 18 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2067: /* module 8 call 19 */
        switch (itemIdx) {
        case 0:
            return "Validators";
        default:
            return NULL;
        }
    case 2068: /* module 8 call 20 */
        switch (itemIdx) {
        case 0:
            return "Stash";
        case 1:
            return "Num slashing spans";
        default:
            return NULL;
        }
    case 2069: /* module 8 call 21 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2070: /* module 8 call 22 */
        switch (itemIdx) {
        case 0:
            return "Era";
        case 1:
            return "Slash indices";
        default:
            return NULL;
        }
    case 2071: /* module 8 call 23 */
        switch (itemIdx) {
        case 0:
            return "Validator stash";
        case 1:
            return "Era";
        default:
            return NULL;
        }
    case 2072: /* module 8 call 24 */
        switch (itemIdx) {
        case 0:
            return "Amount";
        default:
            return NULL;
        }
    case 2073: /* module 8 call 25 */
        switch (itemIdx) {
        case 0:
            return "New history depth";
        case 1:
            return "Era items deleted";
        default:
            return NULL;
        }
    case 2074: /* module 8 call 26 */
        switch (itemIdx) {
        case 0:
            return "Stash";
        case 1:
            return "Num slashing spans";
        default:
            return NULL;
        }
    case 2075: /* module 8 call 27 */
        switch (itemIdx) {
        case 0:
            return "Winners";
        case 1:
            return "Compact";
        case 2:
            return "Score";
        case 3:
            return "Era";
        case 4:
            return "Size";
        default:
            return NULL;
        }
    case 2076: /* module 8 call 28 */
        switch (itemIdx) {
        case 0:
            return "Winners";
        case 1:
            return "Compact";
        case 2:
            return "Score";
        case 3:
            return "Era";
        case 4:
            return "Size";
        default:
            return NULL;
        }
    case 2077: /* module 8 call 29 */
        switch (itemIdx) {
        case 0:
            return "Validator stash";
        case 1:
            return "Era";
        default:
            return NULL;
        }
    case 2078: /* module 8 call 30 */
        switch (itemIdx) {
        case 0:
            return "Slashing switch";
        default:
            return NULL;
        }
    case 2079: /* module 8 call 31 */
        switch (itemIdx) {
        case 0:
            return "Identity";
        case 1:
            return "New intended count";
        default:
            return NULL;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return "Keys";
        case 1:
            return "Proof";
        default:
            return NULL;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0:
            return "Hint";
        default:
            return NULL;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0:
            return "Equivocation proof";
        case 1:
            return "Key owner proof";
        default:
            return NULL;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0:
            return "Equivocation proof";
        case 1:
            return "Key owner proof";
        default:
            return NULL;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0:
            return "Delay";
        case 1:
            return "Best finalized block number";
        default:
            return NULL;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0:
            return "Heartbeat";
        case 1:
            return "Signature";
        default:
            return NULL;
        }
    case 3329: /* module 13 call 1 */
        switch (itemIdx) {
        case 0:
            return "Params";
        default:
            return NULL;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0:
            return "Call";
        default:
            return NULL;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0:
            return "Call";
        case 1:
            return "Weight";
        default:
            return NULL;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0:
            return "New";
        default:
            return NULL;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0:
            return "Who";
        case 1:
            return "Call";
        default:
            return NULL;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0:
            return "Signers";
        case 1:
            return "Sigs required";
        default:
            return NULL;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0:
            return "Multisig";
        case 1:
            return "Proposal";
        case 2:
            return "Expiry";
        case 3:
            return "Auto close";
        default:
            return NULL;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0:
            return "Multisig";
        case 1:
            return "Proposal";
        case 2:
            return "Expiry";
        case 3:
            return "Auto close";
        default:
            return NULL;
        }
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0:
            return "Multisig";
        case 1:
            return "Proposal";
        case 2:
            return "Expiry";
        case 3:
            return "Auto close";
        default:
            return NULL;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0:
            return "Multisig";
        case 1:
            return "Proposal";
        case 2:
            return "Expiry";
        case 3:
            return "Auto close";
        default:
            return NULL;
        }
    case 4613: /* module 18 call 5 */
        switch (itemIdx) {
        case 0:
            return "Multisig";
        case 1:
            return "Proposal id";
        default:
            return NULL;
        }
    case 4614: /* module 18 call 6 */
        switch (itemIdx) {
        case 0:
            return "Multisig";
        case 1:
            return "Proposal id";
        default:
            return NULL;
        }
    case 4615: /* module 18 call 7 */
        switch (itemIdx) {
        case 0:
            return "Multisig";
        case 1:
            return "Proposal id";
        default:
            return NULL;
        }
    case 4616: /* module 18 call 8 */
        switch (itemIdx) {
        case 0:
            return "Multisig";
        case 1:
            return "Proposal id";
        default:
            return NULL;
        }
    case 4617: /* module 18 call 9 */
        switch (itemIdx) {
        case 0:
            return "Auth id";
        default:
            return NULL;
        }
    case 4618: /* module 18 call 10 */
        switch (itemIdx) {
        case 0:
            return "Auth id";
        default:
            return NULL;
        }
    case 4619: /* module 18 call 11 */
        switch (itemIdx) {
        case 0:
            return "Signer";
        default:
            return NULL;
        }
    case 4620: /* module 18 call 12 */
        switch (itemIdx) {
        case 0:
            return "Signer";
        default:
            return NULL;
        }
    case 4621: /* module 18 call 13 */
        switch (itemIdx) {
        case 0:
            return "Multisig";
        case 1:
            return "Signers";
        default:
            return NULL;
        }
    case 4622: /* module 18 call 14 */
        switch (itemIdx) {
        case 0:
            return "Multisig";
        case 1:
            return "Signers";
        default:
            return NULL;
        }
    case 4623: /* module 18 call 15 */
        switch (itemIdx) {
        case 0:
            return "Sigs required";
        default:
            return NULL;
        }
    case 4624: /* module 18 call 16 */
        switch (itemIdx) {
        case 0:
            return "Multisig";
        default:
            return NULL;
        }
    case 4625: /* module 18 call 17 */
        switch (itemIdx) {
        case 0:
            return "Multisig";
        case 1:
            return "Optional cdd auth id";
        default:
            return NULL;
        }
    case 4626: /* module 18 call 18 */
        switch (itemIdx) {
        case 0:
            return "Multisig";
        case 1:
            return "Proposal id";
        case 2:
            return "Multisig did";
        case 3:
            return "Proposal weight";
        default:
            return NULL;
        }
    case 5120: /* module 20 call 0 */
        switch (itemIdx) {
        case 0:
            return "Schedule";
        default:
            return NULL;
        }
    case 5121: /* module 20 call 1 */
        switch (itemIdx) {
        case 0:
            return "Meta info";
        case 1:
            return "Instantiation fee";
        case 2:
            return "Code";
        default:
            return NULL;
        }
    case 5122: /* module 20 call 2 */
        switch (itemIdx) {
        case 0:
            return "Dest";
        case 1:
            return "Amount";
        case 2:
            return "Gas limit";
        case 3:
            return "Data";
        default:
            return NULL;
        }
    case 5123: /* module 20 call 3 */
        switch (itemIdx) {
        case 0:
            return "Endowment";
        case 1:
            return "Gas limit";
        case 2:
            return "Code hash";
        case 3:
            return "Data";
        case 4:
            return "Max fee";
        default:
            return NULL;
        }
    case 5124: /* module 20 call 4 */
        switch (itemIdx) {
        case 0:
            return "Code hash";
        default:
            return NULL;
        }
    case 5125: /* module 20 call 5 */
        switch (itemIdx) {
        case 0:
            return "Code hash";
        default:
            return NULL;
        }
    case 5126: /* module 20 call 6 */
        switch (itemIdx) {
        case 0:
            return "Code hash";
        case 1:
            return "New owner";
        default:
            return NULL;
        }
    case 5127: /* module 20 call 7 */
        switch (itemIdx) {
        case 0:
            return "Code hash";
        case 1:
            return "New instantiation fee";
        case 2:
            return "New usage fee";
        default:
            return NULL;
        }
    case 5128: /* module 20 call 8 */
        switch (itemIdx) {
        case 0:
            return "Code hash";
        case 1:
            return "New url";
        default:
            return NULL;
        }
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0:
            return "Beneficiaries";
        default:
            return NULL;
        }
    case 5377: /* module 21 call 1 */
        switch (itemIdx) {
        case 0:
            return "Amount";
        default:
            return NULL;
        }
    case 5632: /* module 22 call 0 */
        switch (itemIdx) {
        case 0:
            return "N";
        case 1:
            return "D";
        default:
            return NULL;
        }
    case 5633: /* module 22 call 1 */
        switch (itemIdx) {
        case 0:
            return "Id";
        default:
            return NULL;
        }
    case 5634: /* module 22 call 2 */
        switch (itemIdx) {
        case 0:
            return "Expiry";
        default:
            return NULL;
        }
    case 5635: /* module 22 call 3 */
        switch (itemIdx) {
        case 0:
            return "Approve";
        case 1:
            return "Call";
        default:
            return NULL;
        }
    case 5636: /* module 22 call 4 */
        switch (itemIdx) {
        case 0:
            return "Proposal";
        case 1:
            return "Index";
        case 2:
            return "Approve";
        default:
            return NULL;
        }
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        case 0:
            return "Limit";
        default:
            return NULL;
        }
    case 5889: /* module 23 call 1 */
        switch (itemIdx) {
        case 0:
            return "Who";
        case 1:
            return "Expiry";
        case 2:
            return "At";
        default:
            return NULL;
        }
    case 5890: /* module 23 call 2 */
        switch (itemIdx) {
        case 0:
            return "Who";
        default:
            return NULL;
        }
    case 5891: /* module 23 call 3 */
        switch (itemIdx) {
        case 0:
            return "Who";
        default:
            return NULL;
        }
    case 5892: /* module 23 call 4 */
        switch (itemIdx) {
        case 0:
            return "Remove";
        case 1:
            return "Add";
        default:
            return NULL;
        }
    case 5893: /* module 23 call 5 */
        switch (itemIdx) {
        case 0:
            return "Members";
        default:
            return NULL;
        }
    case 5894: /* module 23 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0:
            return "Prune";
        default:
            return NULL;
        }
    case 6145: /* module 24 call 1 */
        switch (itemIdx) {
        case 0:
            return "Deposit";
        default:
            return NULL;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0:
            return "Duration";
        default:
            return NULL;
        }
    case 6147: /* module 24 call 3 */
        switch (itemIdx) {
        case 0:
            return "Expiry";
        default:
            return NULL;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0:
            return "Max";
        default:
            return NULL;
        }
    case 6149: /* module 24 call 5 */
        switch (itemIdx) {
        case 0:
            return "Limit";
        default:
            return NULL;
        }
    case 6150: /* module 24 call 6 */
        switch (itemIdx) {
        case 0:
            return "Proposal";
        case 1:
            return "Deposit";
        case 2:
            return "Url";
        case 3:
            return "Description";
        default:
            return NULL;
        }
    case 6151: /* module 24 call 7 */
        switch (itemIdx) {
        case 0:
            return "Id";
        case 1:
            return "Aye or nay";
        case 2:
            return "Deposit";
        default:
            return NULL;
        }
    case 6152: /* module 24 call 8 */
        switch (itemIdx) {
        case 0:
            return "Id";
        default:
            return NULL;
        }
    case 6153: /* module 24 call 9 */
        switch (itemIdx) {
        case 0:
            return "Id";
        default:
            return NULL;
        }
    case 6154: /* module 24 call 10 */
        switch (itemIdx) {
        case 0:
            return "Id";
        default:
            return NULL;
        }
    case 6155: /* module 24 call 11 */
        switch (itemIdx) {
        case 0:
            return "Id";
        case 1:
            return "Until";
        default:
            return NULL;
        }
    case 6156: /* module 24 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6157: /* module 24 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6158: /* module 24 call 14 */
        switch (itemIdx) {
        case 0:
            return "Results";
        default:
            return NULL;
        }
    case 6159: /* module 24 call 15 */
        switch (itemIdx) {
        case 0:
            return "Id";
        default:
            return NULL;
        }
    case 6160: /* module 24 call 16 */
        switch (itemIdx) {
        case 0:
            return "Did";
        case 1:
            return "Id";
        default:
            return NULL;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        case 0:
            return "N";
        case 1:
            return "D";
        default:
            return NULL;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0:
            return "Id";
        default:
            return NULL;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0:
            return "Expiry";
        default:
            return NULL;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        case 0:
            return "Approve";
        case 1:
            return "Call";
        default:
            return NULL;
        }
    case 6404: /* module 25 call 4 */
        switch (itemIdx) {
        case 0:
            return "Proposal";
        case 1:
            return "Index";
        case 2:
            return "Approve";
        default:
            return NULL;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0:
            return "Limit";
        default:
            return NULL;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0:
            return "Who";
        case 1:
            return "Expiry";
        case 2:
            return "At";
        default:
            return NULL;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0:
            return "Who";
        default:
            return NULL;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        case 0:
            return "Who";
        default:
            return NULL;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0:
            return "Remove";
        case 1:
            return "Add";
        default:
            return NULL;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0:
            return "Members";
        default:
            return NULL;
        }
    case 6662: /* module 26 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0:
            return "N";
        case 1:
            return "D";
        default:
            return NULL;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0:
            return "Id";
        default:
            return NULL;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0:
            return "Expiry";
        default:
            return NULL;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0:
            return "Approve";
        case 1:
            return "Call";
        default:
            return NULL;
        }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0:
            return "Proposal";
        case 1:
            return "Index";
        case 2:
            return "Approve";
        default:
            return NULL;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0:
            return "Limit";
        default:
            return NULL;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0:
            return "Who";
        case 1:
            return "Expiry";
        case 2:
            return "At";
        default:
            return NULL;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0:
            return "Who";
        default:
            return NULL;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        case 0:
            return "Who";
        default:
            return NULL;
        }
    case 7172: /* module 28 call 4 */
        switch (itemIdx) {
        case 0:
            return "Remove";
        case 1:
            return "Add";
        default:
            return NULL;
        }
    case 7173: /* module 28 call 5 */
        switch (itemIdx) {
        case 0:
            return "Members";
        default:
            return NULL;
        }
    case 7174: /* module 28 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        default:
            return NULL;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0:
            return "Auth id";
        default:
            return NULL;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0:
            return "Auth id";
        default:
            return NULL;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        case 0:
            return "Auth id";
        default:
            return NULL;
        }
    case 7428: /* module 29 call 4 */
        switch (itemIdx) {
        case 0:
            return "Name";
        case 1:
            return "Ticker";
        case 2:
            return "Total supply";
        case 3:
            return "Divisible";
        case 4:
            return "Asset type";
        case 5:
            return "Identifiers";
        case 6:
            return "Funding round";
        default:
            return NULL;
        }
    case 7429: /* module 29 call 5 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        default:
            return NULL;
        }
    case 7430: /* module 29 call 6 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        default:
            return NULL;
        }
    case 7431: /* module 29 call 7 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Name";
        default:
            return NULL;
        }
    case 7432: /* module 29 call 8 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Amount";
        default:
            return NULL;
        }
    case 7433: /* module 29 call 9 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Amount";
        default:
            return NULL;
        }
    case 7434: /* module 29 call 10 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        default:
            return NULL;
        }
    case 7435: /* module 29 call 11 */
        switch (itemIdx) {
        case 0:
            return "Docs";
        case 1:
            return "Ticker";
        default:
            return NULL;
        }
    case 7436: /* module 29 call 12 */
        switch (itemIdx) {
        case 0:
            return "Ids";
        case 1:
            return "Ticker";
        default:
            return NULL;
        }
    case 7437: /* module 29 call 13 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Name";
        default:
            return NULL;
        }
    case 7438: /* module 29 call 14 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Identifiers";
        default:
            return NULL;
        }
    case 7439: /* module 29 call 15 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Extension details";
        default:
            return NULL;
        }
    case 7440: /* module 29 call 16 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Extension id";
        default:
            return NULL;
        }
    case 7441: /* module 29 call 17 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Extension id";
        default:
            return NULL;
        }
    case 7442: /* module 29 call 18 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        default:
            return NULL;
        }
    case 7443: /* module 29 call 19 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Extension id";
        default:
            return NULL;
        }
    case 7444: /* module 29 call 20 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Ethereum signature";
        default:
            return NULL;
        }
    case 7445: /* module 29 call 21 */
        switch (itemIdx) {
        case 0:
            return "Classic ticker import";
        case 1:
            return "Contract did";
        case 2:
            return "Config";
        default:
            return NULL;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0:
            return "Controller";
        default:
            return NULL;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0:
            return "Admin";
        default:
            return NULL;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0:
            return "Timelock";
        default:
            return NULL;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7940: /* module 31 call 4 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7941: /* module 31 call 5 */
        switch (itemIdx) {
        case 0:
            return "Amount";
        case 1:
            return "Duration";
        default:
            return NULL;
        }
    case 7942: /* module 31 call 6 */
        switch (itemIdx) {
        case 0:
            return "Exempted";
        default:
            return NULL;
        }
    case 7943: /* module 31 call 7 */
        switch (itemIdx) {
        case 0:
            return "Bridge tx";
        default:
            return NULL;
        }
    case 7944: /* module 31 call 8 */
        switch (itemIdx) {
        case 0:
            return "Bridge txs";
        default:
            return NULL;
        }
    case 7945: /* module 31 call 9 */
        switch (itemIdx) {
        case 0:
            return "Bridge tx";
        default:
            return NULL;
        }
    case 7946: /* module 31 call 10 */
        switch (itemIdx) {
        case 0:
            return "Bridge tx";
        default:
            return NULL;
        }
    case 7947: /* module 31 call 11 */
        switch (itemIdx) {
        case 0:
            return "Bridge txs";
        default:
            return NULL;
        }
    case 7948: /* module 31 call 12 */
        switch (itemIdx) {
        case 0:
            return "Bridge txs";
        default:
            return NULL;
        }
    case 7949: /* module 31 call 13 */
        switch (itemIdx) {
        case 0:
            return "Bridge tx";
        default:
            return NULL;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Sender conditions";
        case 2:
            return "Receiver conditions";
        default:
            return NULL;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Id";
        default:
            return NULL;
        }
    case 8194: /* module 32 call 2 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Asset compliance";
        default:
            return NULL;
        }
    case 8195: /* module 32 call 3 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        default:
            return NULL;
        }
    case 8196: /* module 32 call 4 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        default:
            return NULL;
        }
    case 8197: /* module 32 call 5 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        default:
            return NULL;
        }
    case 8198: /* module 32 call 6 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Issuer";
        default:
            return NULL;
        }
    case 8199: /* module 32 call 7 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Issuer";
        default:
            return NULL;
        }
    case 8200: /* module 32 call 8 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "New req";
        default:
            return NULL;
        }
    case 9216: /* module 36 call 0 */
        switch (itemIdx) {
        case 0:
            return "Details";
        case 1:
            return "Signers";
        case 2:
            return "Venue type";
        default:
            return NULL;
        }
    case 9217: /* module 36 call 1 */
        switch (itemIdx) {
        case 0:
            return "Venue id";
        case 1:
            return "Details";
        case 2:
            return "Typ";
        default:
            return NULL;
        }
    case 9218: /* module 36 call 2 */
        switch (itemIdx) {
        case 0:
            return "Venue id";
        case 1:
            return "Settlement type";
        case 2:
            return "Trade date";
        case 3:
            return "Value date";
        case 4:
            return "Legs";
        default:
            return NULL;
        }
    case 9219: /* module 36 call 3 */
        switch (itemIdx) {
        case 0:
            return "Venue id";
        case 1:
            return "Settlement type";
        case 2:
            return "Trade date";
        case 3:
            return "Value date";
        case 4:
            return "Legs";
        case 5:
            return "Portfolios";
        default:
            return NULL;
        }
    case 9220: /* module 36 call 4 */
        switch (itemIdx) {
        case 0:
            return "Instruction id";
        case 1:
            return "Portfolios";
        case 2:
            return "Max legs count";
        default:
            return NULL;
        }
    case 9221: /* module 36 call 5 */
        switch (itemIdx) {
        case 0:
            return "Instruction id";
        case 1:
            return "Portfolios";
        case 2:
            return "Max legs count";
        default:
            return NULL;
        }
    case 9222: /* module 36 call 6 */
        switch (itemIdx) {
        case 0:
            return "Instruction id";
        case 1:
            return "Portfolios";
        case 2:
            return "Max legs count";
        default:
            return NULL;
        }
    case 9223: /* module 36 call 7 */
        switch (itemIdx) {
        case 0:
            return "Instruction id";
        case 1:
            return "Receipt details";
        case 2:
            return "Portfolios";
        case 3:
            return "Max legs count";
        default:
            return NULL;
        }
    case 9224: /* module 36 call 8 */
        switch (itemIdx) {
        case 0:
            return "Instruction id";
        case 1:
            return "Receipt details";
        default:
            return NULL;
        }
    case 9225: /* module 36 call 9 */
        switch (itemIdx) {
        case 0:
            return "Instruction id";
        case 1:
            return "Leg id";
        default:
            return NULL;
        }
    case 9226: /* module 36 call 10 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Enabled";
        default:
            return NULL;
        }
    case 9227: /* module 36 call 11 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Venues";
        default:
            return NULL;
        }
    case 9228: /* module 36 call 12 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Venues";
        default:
            return NULL;
        }
    case 9229: /* module 36 call 13 */
        switch (itemIdx) {
        case 0:
            return "Instruction id";
        case 1:
            return "Legs count";
        default:
            return NULL;
        }
    case 9472: /* module 37 call 0 */
        switch (itemIdx) {
        case 0:
            return "Offering portfolio";
        case 1:
            return "Offering asset";
        case 2:
            return "Raising portfolio";
        case 3:
            return "Raising asset";
        case 4:
            return "Tiers";
        case 5:
            return "Venue id";
        case 6:
            return "Start";
        case 7:
            return "End";
        case 8:
            return "Minimum investment";
        case 9:
            return "Fundraiser name";
        default:
            return NULL;
        }
    case 9473: /* module 37 call 1 */
        switch (itemIdx) {
        case 0:
            return "Investment portfolio";
        case 1:
            return "Funding portfolio";
        case 2:
            return "Offering asset";
        case 3:
            return "Fundraiser id";
        case 4:
            return "Investment amount";
        case 5:
            return "Max price";
        case 6:
            return "Receipt";
        default:
            return NULL;
        }
    case 9474: /* module 37 call 2 */
        switch (itemIdx) {
        case 0:
            return "Offering asset";
        case 1:
            return "Fundraiser id";
        default:
            return NULL;
        }
    case 9475: /* module 37 call 3 */
        switch (itemIdx) {
        case 0:
            return "Offering asset";
        case 1:
            return "Fundraiser id";
        default:
            return NULL;
        }
    case 9476: /* module 37 call 4 */
        switch (itemIdx) {
        case 0:
            return "Offering asset";
        case 1:
            return "Fundraiser id";
        case 2:
            return "Start";
        case 3:
            return "End";
        default:
            return NULL;
        }
    case 9477: /* module 37 call 5 */
        switch (itemIdx) {
        case 0:
            return "Offering asset";
        case 1:
            return "Fundraiser id";
        default:
            return NULL;
        }
    case 9728: /* module 38 call 0 */
        switch (itemIdx) {
        case 0:
            return "Limit";
        default:
            return NULL;
        }
    case 9729: /* module 38 call 1 */
        switch (itemIdx) {
        case 0:
            return "Who";
        case 1:
            return "Expiry";
        case 2:
            return "At";
        default:
            return NULL;
        }
    case 9730: /* module 38 call 2 */
        switch (itemIdx) {
        case 0:
            return "Who";
        default:
            return NULL;
        }
    case 9731: /* module 38 call 3 */
        switch (itemIdx) {
        case 0:
            return "Who";
        default:
            return NULL;
        }
    case 9732: /* module 38 call 4 */
        switch (itemIdx) {
        case 0:
            return "Remove";
        case 1:
            return "Add";
        default:
            return NULL;
        }
    case 9733: /* module 38 call 5 */
        switch (itemIdx) {
        case 0:
            return "Members";
        default:
            return NULL;
        }
    case 9734: /* module 38 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 9984: /* module 39 call 0 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "New transfer manager";
        default:
            return NULL;
        }
    case 9985: /* module 39 call 1 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Transfer manager";
        default:
            return NULL;
        }
    case 9986: /* module 39 call 2 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Transfer manager";
        case 2:
            return "Exempted entities";
        default:
            return NULL;
        }
    case 9987: /* module 39 call 3 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Transfer manager";
        case 2:
            return "Entities";
        default:
            return NULL;
        }
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0:
            return "Coefficient";
        default:
            return NULL;
        }
    case 10241: /* module 40 call 1 */
        switch (itemIdx) {
        case 0:
            return "Op";
        case 1:
            return "Base fee";
        default:
            return NULL;
        }
    case 10496: /* module 41 call 0 */
        switch (itemIdx) {
        case 0:
            return "Calls";
        default:
            return NULL;
        }
    case 10497: /* module 41 call 1 */
        switch (itemIdx) {
        case 0:
            return "Calls";
        default:
            return NULL;
        }
    case 10498: /* module 41 call 2 */
        switch (itemIdx) {
        case 0:
            return "Calls";
        default:
            return NULL;
        }
    case 10499: /* module 41 call 3 */
        switch (itemIdx) {
        case 0:
            return "Target";
        case 1:
            return "Signature";
        case 2:
            return "Call";
        default:
            return NULL;
        }
    case 10752: /* module 42 call 0 */
        switch (itemIdx) {
        case 0:
            return "Name";
        default:
            return NULL;
        }
    case 10753: /* module 42 call 1 */
        switch (itemIdx) {
        case 0:
            return "Num";
        default:
            return NULL;
        }
    case 10754: /* module 42 call 2 */
        switch (itemIdx) {
        case 0:
            return "From";
        case 1:
            return "To";
        case 2:
            return "Items";
        default:
            return NULL;
        }
    case 10755: /* module 42 call 3 */
        switch (itemIdx) {
        case 0:
            return "Num";
        case 1:
            return "To name";
        default:
            return NULL;
        }
    case 11008: /* module 43 call 0 */
        switch (itemIdx) {
        case 0:
            return "Target id";
        case 1:
            return "Ticker";
        case 2:
            return "Secret value";
        default:
            return NULL;
        }
    case 11009: /* module 43 call 1 */
        switch (itemIdx) {
        case 0:
            return "Target";
        case 1:
            return "Prover";
        case 2:
            return "Ticker";
        default:
            return NULL;
        }
    case 11520: /* module 45 call 0 */
        switch (itemIdx) {
        case 0:
            return "When";
        case 1:
            return "Maybe periodic";
        case 2:
            return "Priority";
        case 3:
            return "Call";
        default:
            return NULL;
        }
    case 11521: /* module 45 call 1 */
        switch (itemIdx) {
        case 0:
            return "When";
        case 1:
            return "Index";
        default:
            return NULL;
        }
    case 11522: /* module 45 call 2 */
        switch (itemIdx) {
        case 0:
            return "Id";
        case 1:
            return "When";
        case 2:
            return "Maybe periodic";
        case 3:
            return "Priority";
        case 4:
            return "Call";
        default:
            return NULL;
        }
    case 11523: /* module 45 call 3 */
        switch (itemIdx) {
        case 0:
            return "Id";
        default:
            return NULL;
        }
    case 11524: /* module 45 call 4 */
        switch (itemIdx) {
        case 0:
            return "After";
        case 1:
            return "Maybe periodic";
        case 2:
            return "Priority";
        case 3:
            return "Call";
        default:
            return NULL;
        }
    case 11525: /* module 45 call 5 */
        switch (itemIdx) {
        case 0:
            return "Id";
        case 1:
            return "After";
        case 2:
            return "Maybe periodic";
        case 3:
            return "Priority";
        case 4:
            return "Call";
        default:
            return NULL;
        }
    case 11776: /* module 46 call 0 */
        switch (itemIdx) {
        case 0:
            return "Length";
        default:
            return NULL;
        }
    case 11777: /* module 46 call 1 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        default:
            return NULL;
        }
    case 11778: /* module 46 call 2 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Targets";
        default:
            return NULL;
        }
    case 11779: /* module 46 call 3 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Tax";
        default:
            return NULL;
        }
    case 11780: /* module 46 call 4 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Taxed did";
        case 2:
            return "Tax";
        default:
            return NULL;
        }
    case 11781: /* module 46 call 5 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Kind";
        case 2:
            return "Decl date";
        case 3:
            return "Record date";
        case 4:
            return "Details";
        case 5:
            return "Targets";
        case 6:
            return "Default withholding tax";
        case 7:
            return "Withholding tax";
        default:
            return NULL;
        }
    case 11782: /* module 46 call 6 */
        switch (itemIdx) {
        case 0:
            return "Id";
        case 1:
            return "Docs";
        default:
            return NULL;
        }
    case 11783: /* module 46 call 7 */
        switch (itemIdx) {
        case 0:
            return "Ca id";
        default:
            return NULL;
        }
    case 11784: /* module 46 call 8 */
        switch (itemIdx) {
        case 0:
            return "Ca id";
        case 1:
            return "Record date";
        default:
            return NULL;
        }
    case 12032: /* module 47 call 0 */
        switch (itemIdx) {
        case 0:
            return "Ca id";
        case 1:
            return "Range";
        case 2:
            return "Meta";
        case 3:
            return "Rcv";
        default:
            return NULL;
        }
    case 12033: /* module 47 call 1 */
        switch (itemIdx) {
        case 0:
            return "Ca id";
        case 1:
            return "Votes";
        default:
            return NULL;
        }
    case 12034: /* module 47 call 2 */
        switch (itemIdx) {
        case 0:
            return "Ca id";
        case 1:
            return "End";
        default:
            return NULL;
        }
    case 12035: /* module 47 call 3 */
        switch (itemIdx) {
        case 0:
            return "Ca id";
        case 1:
            return "Meta";
        default:
            return NULL;
        }
    case 12036: /* module 47 call 4 */
        switch (itemIdx) {
        case 0:
            return "Ca id";
        case 1:
            return "Rcv";
        default:
            return NULL;
        }
    case 12037: /* module 47 call 5 */
        switch (itemIdx) {
        case 0:
            return "Ca id";
        default:
            return NULL;
        }
    case 12288: /* module 48 call 0 */
        switch (itemIdx) {
        case 0:
            return "Ca id";
        case 1:
            return "Portfolio";
        case 2:
            return "Currency";
        case 3:
            return "Amount";
        case 4:
            return "Payment at";
        case 5:
            return "Expires at";
        default:
            return NULL;
        }
    case 12289: /* module 48 call 1 */
        switch (itemIdx) {
        case 0:
            return "Ca id";
        default:
            return NULL;
        }
    case 12290: /* module 48 call 2 */
        switch (itemIdx) {
        case 0:
            return "Ca id";
        case 1:
            return "Holder";
        default:
            return NULL;
        }
    case 12291: /* module 48 call 3 */
        switch (itemIdx) {
        case 0:
            return "Ca id";
        default:
            return NULL;
        }
    case 12292: /* module 48 call 4 */
        switch (itemIdx) {
        case 0:
            return "Ca id";
        default:
            return NULL;
        }
    case 12544: /* module 49 call 0 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        default:
            return NULL;
        }
    case 12545: /* module 49 call 1 */
        switch (itemIdx) {
        case 0:
            return "Max complexity";
        default:
            return NULL;
        }
    case 12546: /* module 49 call 2 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Schedule";
        default:
            return NULL;
        }
    case 12547: /* module 49 call 3 */
        switch (itemIdx) {
        case 0:
            return "Ticker";
        case 1:
            return "Id";
        default:
            return NULL;
        }
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V5(
    pd_Method_V5_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_fill_block_V5 - _ratio */;
            return _toStringPerbill_V5(
                &m->basic.system_fill_block_V5._ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V5 - _remark */;
            return _toStringBytes(
                &m->basic.system_remark_V5._remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V5 - pages */;
            return _toStringu64(
                &m->basic.system_set_heap_pages_V5.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V5 - code */;
            return _toStringBytes(
                &m->basic.system_set_code_V5.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V5 - code */;
            return _toStringBytes(
                &m->basic.system_set_code_without_checks_V5.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5: /* module 0 call 5 */
        switch (itemIdx) {
        case 0: /* system_set_changes_trie_config_V5 - changes_trie_config */;
            return _toStringOptionChangesTrieConfiguration_V5(
                &m->basic.system_set_changes_trie_config_V5.changes_trie_config,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6: /* module 0 call 6 */
        switch (itemIdx) {
        case 0: /* system_set_storage_V5 - items */;
            return _toStringVecKeyValue_V5(
                &m->basic.system_set_storage_V5.items,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0: /* system_kill_storage_V5 - keys */;
            return _toStringVecKey_V5(
                &m->basic.system_kill_storage_V5.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0: /* system_kill_prefix_V5 - prefix */;
            return _toStringKey_V5(
                &m->basic.system_kill_prefix_V5.prefix,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* system_kill_prefix_V5 - _subkeys */;
            return _toStringu32(
                &m->basic.system_kill_prefix_V5._subkeys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9: /* module 0 call 9 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0: /* babe_report_equivocation_V5 - equivocation_proof */;
            return _toStringEquivocationProof_V5(
                &m->basic.babe_report_equivocation_V5.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* babe_report_equivocation_V5 - key_owner_proof */;
            return _toStringKeyOwnerProof_V5(
                &m->basic.babe_report_equivocation_V5.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 257: /* module 1 call 1 */
        switch (itemIdx) {
        case 0: /* babe_report_equivocation_unsigned_V5 - equivocation_proof */;
            return _toStringEquivocationProof_V5(
                &m->basic.babe_report_equivocation_unsigned_V5.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* babe_report_equivocation_unsigned_V5 - key_owner_proof */;
            return _toStringKeyOwnerProof_V5(
                &m->basic.babe_report_equivocation_unsigned_V5.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V5 - now */;
            return _toStringCompactMoment_V5(
                &m->basic.timestamp_set_V5.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* indices_claim_V5 - index */;
            return _toStringAccountIndex_V5(
                &m->basic.indices_claim_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 769: /* module 3 call 1 */
        switch (itemIdx) {
        case 0: /* indices_transfer_V5 - new_ */;
            return _toStringAccountId_V5(
                &m->basic.indices_transfer_V5.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_transfer_V5 - index */;
            return _toStringAccountIndex_V5(
                &m->basic.indices_transfer_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0: /* indices_free_V5 - index */;
            return _toStringAccountIndex_V5(
                &m->basic.indices_free_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 771: /* module 3 call 3 */
        switch (itemIdx) {
        case 0: /* indices_force_transfer_V5 - new_ */;
            return _toStringAccountId_V5(
                &m->basic.indices_force_transfer_V5.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_force_transfer_V5 - index */;
            return _toStringAccountIndex_V5(
                &m->basic.indices_force_transfer_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* indices_force_transfer_V5 - freeze */;
            return _toStringbool(
                &m->basic.indices_force_transfer_V5.freeze,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 772: /* module 3 call 4 */
        switch (itemIdx) {
        case 0: /* indices_freeze_V5 - index */;
            return _toStringAccountIndex_V5(
                &m->basic.indices_freeze_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V5 - dest */;
            return _toStringLookupSource(
                &m->basic.balances_transfer_V5.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V5 - value */;
            return _toStringCompactBalance(
                &m->basic.balances_transfer_V5.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0: /* balances_transfer_with_memo_V5 - dest */;
            return _toStringLookupSource(
                &m->basic.balances_transfer_with_memo_V5.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_with_memo_V5 - value */;
            return _toStringCompactBalance(
                &m->basic.balances_transfer_with_memo_V5.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_transfer_with_memo_V5 - memo */;
            return _toStringOptionMemo_V5(
                &m->basic.balances_transfer_with_memo_V5.memo,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0: /* balances_deposit_block_reward_reserve_balance_V5 - value */;
            return _toStringCompactBalance(
                &m->basic.balances_deposit_block_reward_reserve_balance_V5.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V5 - who */;
            return _toStringLookupSource(
                &m->basic.balances_set_balance_V5.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V5 - new_free */;
            return _toStringCompactBalance(
                &m->basic.balances_set_balance_V5.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V5 - new_reserved */;
            return _toStringCompactBalance(
                &m->basic.balances_set_balance_V5.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V5 - source */;
            return _toStringLookupSource(
                &m->basic.balances_force_transfer_V5.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V5 - dest */;
            return _toStringLookupSource(
                &m->basic.balances_force_transfer_V5.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V5 - value */;
            return _toStringCompactBalance(
                &m->basic.balances_force_transfer_V5.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1029: /* module 4 call 5 */
        switch (itemIdx) {
        case 0: /* balances_burn_account_balance_V5 - amount */;
            return _toStringBalance(
                &m->basic.balances_burn_account_balance_V5.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* identity_register_did_V5 - uid */;
            return _toStringInvestorUid_V5(
                &m->basic.identity_register_did_V5.uid,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_register_did_V5 - secondary_keys */;
            return _toStringVecSecondaryKey_V5(
                &m->basic.identity_register_did_V5.secondary_keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0: /* identity_cdd_register_did_V5 - target_account */;
            return _toStringAccountId_V5(
                &m->basic.identity_cdd_register_did_V5.target_account,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_cdd_register_did_V5 - secondary_keys */;
            return _toStringVecSecondaryKey_V5(
                &m->basic.identity_cdd_register_did_V5.secondary_keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0: /* identity_mock_cdd_register_did_V5 - target_account */;
            return _toStringAccountId_V5(
                &m->basic.identity_mock_cdd_register_did_V5.target_account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0: /* identity_invalidate_cdd_claims_V5 - cdd */;
            return _toStringIdentityId_V5(
                &m->basic.identity_invalidate_cdd_claims_V5.cdd,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_invalidate_cdd_claims_V5 - disable_from */;
            return _toStringMoment_V5(
                &m->basic.identity_invalidate_cdd_claims_V5.disable_from,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_invalidate_cdd_claims_V5 - expiry */;
            return _toStringOptionMoment_V5(
                &m->basic.identity_invalidate_cdd_claims_V5.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0: /* identity_remove_secondary_keys_V5 - signers_to_remove */;
            return _toStringVecSignatory_V5(
                &m->basic.identity_remove_secondary_keys_V5.signers_to_remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0: /* identity_accept_primary_key_V5 - rotation_auth_id */;
            return _toStringu64(
                &m->basic.identity_accept_primary_key_V5.rotation_auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_accept_primary_key_V5 - optional_cdd_auth_id */;
            return _toStringOptionu64(
                &m->basic.identity_accept_primary_key_V5.optional_cdd_auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1542: /* module 6 call 6 */
        switch (itemIdx) {
        case 0: /* identity_change_cdd_requirement_for_mk_rotation_V5 - auth_required */;
            return _toStringbool(
                &m->basic.identity_change_cdd_requirement_for_mk_rotation_V5.auth_required,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1543: /* module 6 call 7 */
        switch (itemIdx) {
        case 0: /* identity_join_identity_as_key_V5 - auth_id */;
            return _toStringu64(
                &m->basic.identity_join_identity_as_key_V5.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0: /* identity_join_identity_as_identity_V5 - auth_id */;
            return _toStringu64(
                &m->basic.identity_join_identity_as_identity_V5.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1545: /* module 6 call 9 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1546: /* module 6 call 10 */
        switch (itemIdx) {
        case 0: /* identity_leave_identity_as_identity_V5 - did */;
            return _toStringIdentityId_V5(
                &m->basic.identity_leave_identity_as_identity_V5.did,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1547: /* module 6 call 11 */
        switch (itemIdx) {
        case 0: /* identity_add_claim_V5 - target */;
            return _toStringIdentityId_V5(
                &m->basic.identity_add_claim_V5.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_claim_V5 - claim */;
            return _toStringClaim_V5(
                &m->basic.identity_add_claim_V5.claim,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_add_claim_V5 - expiry */;
            return _toStringOptionMoment_V5(
                &m->basic.identity_add_claim_V5.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1548: /* module 6 call 12 */
        switch (itemIdx) {
        case 0: /* identity_forwarded_call_V5 - target_did */;
            return _toStringIdentityId_V5(
                &m->nested.identity_forwarded_call_V5.target_did,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_forwarded_call_V5 - proposal */;
            return _toStringProposal(
                &m->nested.identity_forwarded_call_V5.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1549: /* module 6 call 13 */
        switch (itemIdx) {
        case 0: /* identity_revoke_claim_V5 - target */;
            return _toStringIdentityId_V5(
                &m->basic.identity_revoke_claim_V5.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_revoke_claim_V5 - claim */;
            return _toStringClaim_V5(
                &m->basic.identity_revoke_claim_V5.claim,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1550: /* module 6 call 14 */
        switch (itemIdx) {
        case 0: /* identity_set_permission_to_signer_V5 - signer */;
            return _toStringSignatory_V5(
                &m->basic.identity_set_permission_to_signer_V5.signer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_permission_to_signer_V5 - permissions */;
            return _toStringPermissions_V5(
                &m->basic.identity_set_permission_to_signer_V5.permissions,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1551: /* module 6 call 15 */
        switch (itemIdx) {
        case 0: /* identity_legacy_set_permission_to_signer_V5 - signer */;
            return _toStringSignatory_V5(
                &m->basic.identity_legacy_set_permission_to_signer_V5.signer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_legacy_set_permission_to_signer_V5 - permissions */;
            return _toStringLegacyPermissions_V5(
                &m->basic.identity_legacy_set_permission_to_signer_V5.permissions,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1552: /* module 6 call 16 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1553: /* module 6 call 17 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1554: /* module 6 call 18 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1555: /* module 6 call 19 */
        switch (itemIdx) {
        case 0: /* identity_get_cdd_of_V5 - of */;
            return _toStringAccountId_V5(
                &m->basic.identity_get_cdd_of_V5.of,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1556: /* module 6 call 20 */
        switch (itemIdx) {
        case 0: /* identity_add_authorization_V5 - target */;
            return _toStringSignatory_V5(
                &m->basic.identity_add_authorization_V5.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_authorization_V5 - authorization_data */;
            return _toStringAuthorizationData_V5(
                &m->basic.identity_add_authorization_V5.authorization_data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_add_authorization_V5 - expiry */;
            return _toStringOptionMoment_V5(
                &m->basic.identity_add_authorization_V5.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1557: /* module 6 call 21 */
        switch (itemIdx) {
        case 0: /* identity_remove_authorization_V5 - target */;
            return _toStringSignatory_V5(
                &m->basic.identity_remove_authorization_V5.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_remove_authorization_V5 - auth_id */;
            return _toStringu64(
                &m->basic.identity_remove_authorization_V5.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_remove_authorization_V5 - _auth_issuer_pays */;
            return _toStringbool(
                &m->basic.identity_remove_authorization_V5._auth_issuer_pays,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1558: /* module 6 call 22 */
        switch (itemIdx) {
        case 0: /* identity_accept_authorization_V5 - auth_id */;
            return _toStringu64(
                &m->basic.identity_accept_authorization_V5.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1559: /* module 6 call 23 */
        switch (itemIdx) {
        case 0: /* identity_add_secondary_keys_with_authorization_V5 - additional_keys */;
            return _toStringVecSecondaryKeyWithAuth_V5(
                &m->basic.identity_add_secondary_keys_with_authorization_V5.additional_keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_secondary_keys_with_authorization_V5 - expires_at */;
            return _toStringMoment_V5(
                &m->basic.identity_add_secondary_keys_with_authorization_V5.expires_at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1560: /* module 6 call 24 */
        switch (itemIdx) {
        case 0: /* identity_revoke_offchain_authorization_V5 - signer */;
            return _toStringSignatory_V5(
                &m->basic.identity_revoke_offchain_authorization_V5.signer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_revoke_offchain_authorization_V5 - auth */;
            return _toStringTargetIdAuthorization_V5(
                &m->basic.identity_revoke_offchain_authorization_V5.auth,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1561: /* module 6 call 25 */
        switch (itemIdx) {
        case 0: /* identity_add_investor_uniqueness_claim_V5 - target */;
            return _toStringIdentityId_V5(
                &m->basic.identity_add_investor_uniqueness_claim_V5.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_investor_uniqueness_claim_V5 - claim */;
            return _toStringClaim_V5(
                &m->basic.identity_add_investor_uniqueness_claim_V5.claim,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_add_investor_uniqueness_claim_V5 - proof */;
            return _toStringInvestorZKProofData_V5(
                &m->basic.identity_add_investor_uniqueness_claim_V5.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* identity_add_investor_uniqueness_claim_V5 - expiry */;
            return _toStringOptionMoment_V5(
                &m->basic.identity_add_investor_uniqueness_claim_V5.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1562: /* module 6 call 26 */
        switch (itemIdx) {
        case 0: /* identity_gc_add_cdd_claim_V5 - target */;
            return _toStringIdentityId_V5(
                &m->basic.identity_gc_add_cdd_claim_V5.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_gc_add_cdd_claim_V5 - expiry */;
            return _toStringOptionMoment_V5(
                &m->basic.identity_gc_add_cdd_claim_V5.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1563: /* module 6 call 27 */
        switch (itemIdx) {
        case 0: /* identity_gc_revoke_cdd_claim_V5 - target */;
            return _toStringIdentityId_V5(
                &m->basic.identity_gc_revoke_cdd_claim_V5.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1792: /* module 7 call 0 */
        switch (itemIdx) {
        case 0: /* authorship_set_uncles_V5 - new_uncles */;
            return _toStringVecHeader(
                &m->basic.authorship_set_uncles_V5.new_uncles,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V5 - controller */;
            return _toStringLookupSource(
                &m->basic.staking_bond_V5.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V5 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_bond_V5.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_bond_V5 - payee */;
            return _toStringRewardDestination_V5(
                &m->basic.staking_bond_V5.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V5 - max_additional */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_bond_extra_V5.max_additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2050: /* module 8 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V5 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_unbond_V5.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2051: /* module 8 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V5 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_withdraw_unbonded_V5.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2052: /* module 8 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V5 - prefs */;
            return _toStringValidatorPrefs_V5(
                &m->basic.staking_validate_V5.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2053: /* module 8 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V5 - targets */;
            return _toStringVecLookupSource(
                &m->basic.staking_nominate_V5.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2054: /* module 8 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2055: /* module 8 call 7 */
        switch (itemIdx) {
        case 0: /* staking_set_payee_V5 - payee */;
            return _toStringRewardDestination_V5(
                &m->basic.staking_set_payee_V5.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2056: /* module 8 call 8 */
        switch (itemIdx) {
        case 0: /* staking_set_controller_V5 - controller */;
            return _toStringLookupSource(
                &m->basic.staking_set_controller_V5.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2057: /* module 8 call 9 */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V5 - new_ */;
            return _toStringCompactu32(
                &m->basic.staking_set_validator_count_V5.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2058: /* module 8 call 10 */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V5 - additional */;
            return _toStringCompactu32(
                &m->basic.staking_increase_validator_count_V5.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2059: /* module 8 call 11 */
        switch (itemIdx) {
        case 0: /* staking_scale_validator_count_V5 - factor */;
            return _toStringPercent_V5(
                &m->basic.staking_scale_validator_count_V5.factor,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2060: /* module 8 call 12 */
        switch (itemIdx) {
        case 0: /* staking_add_permissioned_validator_V5 - identity */;
            return _toStringIdentityId_V5(
                &m->basic.staking_add_permissioned_validator_V5.identity,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_add_permissioned_validator_V5 - intended_count */;
            return _toStringOptionu32(
                &m->basic.staking_add_permissioned_validator_V5.intended_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2061: /* module 8 call 13 */
        switch (itemIdx) {
        case 0: /* staking_remove_permissioned_validator_V5 - identity */;
            return _toStringIdentityId_V5(
                &m->basic.staking_remove_permissioned_validator_V5.identity,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2062: /* module 8 call 14 */
        switch (itemIdx) {
        case 0: /* staking_validate_cdd_expiry_nominators_V5 - targets */;
            return _toStringVecAccountId_V5(
                &m->basic.staking_validate_cdd_expiry_nominators_V5.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2063: /* module 8 call 15 */
        switch (itemIdx) {
        case 0: /* staking_set_commission_cap_V5 - new_cap */;
            return _toStringPerbill_V5(
                &m->basic.staking_set_commission_cap_V5.new_cap,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2064: /* module 8 call 16 */
        switch (itemIdx) {
        case 0: /* staking_set_min_bond_threshold_V5 - new_value */;
            return _toStringBalanceOf(
                &m->basic.staking_set_min_bond_threshold_V5.new_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2065: /* module 8 call 17 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2066: /* module 8 call 18 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2067: /* module 8 call 19 */
        switch (itemIdx) {
        case 0: /* staking_set_invulnerables_V5 - validators */;
            return _toStringVecAccountId_V5(
                &m->basic.staking_set_invulnerables_V5.validators,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2068: /* module 8 call 20 */
        switch (itemIdx) {
        case 0: /* staking_force_unstake_V5 - stash */;
            return _toStringAccountId_V5(
                &m->basic.staking_force_unstake_V5.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_force_unstake_V5 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_force_unstake_V5.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2069: /* module 8 call 21 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2070: /* module 8 call 22 */
        switch (itemIdx) {
        case 0: /* staking_cancel_deferred_slash_V5 - era */;
            return _toStringEraIndex_V5(
                &m->basic.staking_cancel_deferred_slash_V5.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_cancel_deferred_slash_V5 - slash_indices */;
            return _toStringVecu32(
                &m->basic.staking_cancel_deferred_slash_V5.slash_indices,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2071: /* module 8 call 23 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V5 - validator_stash */;
            return _toStringAccountId_V5(
                &m->basic.staking_payout_stakers_V5.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V5 - era */;
            return _toStringEraIndex_V5(
                &m->basic.staking_payout_stakers_V5.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2072: /* module 8 call 24 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V5 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_rebond_V5.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2073: /* module 8 call 25 */
        switch (itemIdx) {
        case 0: /* staking_set_history_depth_V5 - new_history_depth */;
            return _toStringCompactEraIndex_V5(
                &m->basic.staking_set_history_depth_V5.new_history_depth,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_history_depth_V5 - _era_items_deleted */;
            return _toStringCompactu32(
                &m->basic.staking_set_history_depth_V5._era_items_deleted,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2074: /* module 8 call 26 */
        switch (itemIdx) {
        case 0: /* staking_reap_stash_V5 - stash */;
            return _toStringAccountId_V5(
                &m->basic.staking_reap_stash_V5.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_reap_stash_V5 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_reap_stash_V5.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2075: /* module 8 call 27 */
        switch (itemIdx) {
        case 0: /* staking_submit_election_solution_V5 - winners */;
            return _toStringVecValidatorIndex_V5(
                &m->basic.staking_submit_election_solution_V5.winners,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_submit_election_solution_V5 - compact */;
            return _toStringCompactAssignments_V5(
                &m->basic.staking_submit_election_solution_V5.compact,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_submit_election_solution_V5 - score */;
            return _toStringElectionScore_V5(
                &m->basic.staking_submit_election_solution_V5.score,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* staking_submit_election_solution_V5 - era */;
            return _toStringEraIndex_V5(
                &m->basic.staking_submit_election_solution_V5.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* staking_submit_election_solution_V5 - size */;
            return _toStringElectionSize_V5(
                &m->basic.staking_submit_election_solution_V5.size,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2076: /* module 8 call 28 */
        switch (itemIdx) {
        case 0: /* staking_submit_election_solution_unsigned_V5 - winners */;
            return _toStringVecValidatorIndex_V5(
                &m->basic.staking_submit_election_solution_unsigned_V5.winners,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_submit_election_solution_unsigned_V5 - compact */;
            return _toStringCompactAssignments_V5(
                &m->basic.staking_submit_election_solution_unsigned_V5.compact,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_submit_election_solution_unsigned_V5 - score */;
            return _toStringElectionScore_V5(
                &m->basic.staking_submit_election_solution_unsigned_V5.score,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* staking_submit_election_solution_unsigned_V5 - era */;
            return _toStringEraIndex_V5(
                &m->basic.staking_submit_election_solution_unsigned_V5.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* staking_submit_election_solution_unsigned_V5 - size */;
            return _toStringElectionSize_V5(
                &m->basic.staking_submit_election_solution_unsigned_V5.size,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2077: /* module 8 call 29 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_by_system_V5 - validator_stash */;
            return _toStringAccountId_V5(
                &m->basic.staking_payout_stakers_by_system_V5.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_by_system_V5 - era */;
            return _toStringEraIndex_V5(
                &m->basic.staking_payout_stakers_by_system_V5.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2078: /* module 8 call 30 */
        switch (itemIdx) {
        case 0: /* staking_change_slashing_allowed_for_V5 - slashing_switch */;
            return _toStringSlashingSwitch_V5(
                &m->basic.staking_change_slashing_allowed_for_V5.slashing_switch,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2079: /* module 8 call 31 */
        switch (itemIdx) {
        case 0: /* staking_update_permissioned_validator_intended_count_V5 - identity */;
            return _toStringIdentityId_V5(
                &m->basic.staking_update_permissioned_validator_intended_count_V5.identity,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_update_permissioned_validator_intended_count_V5 - new_intended_count */;
            return _toStringu32(
                &m->basic.staking_update_permissioned_validator_intended_count_V5.new_intended_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V5 - keys */;
            return _toStringKeys_V5(
                &m->basic.session_set_keys_V5.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V5 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V5.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0: /* finalitytracker_final_hint_V5 - hint */;
            return _toStringCompactBlockNumber(
                &m->basic.finalitytracker_final_hint_V5.hint,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0: /* grandpa_report_equivocation_V5 - equivocation_proof */;
            return _toStringEquivocationProof_V5(
                &m->basic.grandpa_report_equivocation_V5.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_report_equivocation_V5 - key_owner_proof */;
            return _toStringKeyOwnerProof_V5(
                &m->basic.grandpa_report_equivocation_V5.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0: /* grandpa_report_equivocation_unsigned_V5 - equivocation_proof */;
            return _toStringEquivocationProof_V5(
                &m->basic.grandpa_report_equivocation_unsigned_V5.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_report_equivocation_unsigned_V5 - key_owner_proof */;
            return _toStringKeyOwnerProof_V5(
                &m->basic.grandpa_report_equivocation_unsigned_V5.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0: /* grandpa_note_stalled_V5 - delay */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V5.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_note_stalled_V5 - best_finalized_block_number */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V5.best_finalized_block_number,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0: /* imonline_heartbeat_V5 - heartbeat */;
            return _toStringHeartbeat(
                &m->basic.imonline_heartbeat_V5.heartbeat,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* imonline_heartbeat_V5 - _signature */;
            return _toStringSignature_V5(
                &m->basic.imonline_heartbeat_V5._signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3329: /* module 13 call 1 */
        switch (itemIdx) {
        case 0: /* imonline_set_slashing_params_V5 - params */;
            return _toStringOfflineSlashingParams_V5(
                &m->basic.imonline_set_slashing_params_V5.params,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_V5 - call */;
            return _toStringCall(
                &m->nested.sudo_sudo_V5.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_unchecked_weight_V5 - call */;
            return _toStringCall(
                &m->nested.sudo_sudo_unchecked_weight_V5.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sudo_sudo_unchecked_weight_V5 - _weight */;
            return _toStringWeight_V5(
                &m->nested.sudo_sudo_unchecked_weight_V5._weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0: /* sudo_set_key_V5 - new_ */;
            return _toStringLookupSource(
                &m->basic.sudo_set_key_V5.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_as_V5 - who */;
            return _toStringLookupSource(
                &m->nested.sudo_sudo_as_V5.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sudo_sudo_as_V5 - call */;
            return _toStringCall(
                &m->nested.sudo_sudo_as_V5.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_create_multisig_V5 - signers */;
            return _toStringVecSignatory_V5(
                &m->basic.multisig_create_multisig_V5.signers,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_create_multisig_V5 - sigs_required */;
            return _toStringu64(
                &m->basic.multisig_create_multisig_V5.sigs_required,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_create_or_approve_proposal_as_identity_V5 - multisig */;
            return _toStringAccountId_V5(
                &m->nested.multisig_create_or_approve_proposal_as_identity_V5.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_create_or_approve_proposal_as_identity_V5 - proposal */;
            return _toStringProposal(
                &m->nested.multisig_create_or_approve_proposal_as_identity_V5.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_create_or_approve_proposal_as_identity_V5 - expiry */;
            return _toStringOptionMoment_V5(
                &m->nested.multisig_create_or_approve_proposal_as_identity_V5.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_create_or_approve_proposal_as_identity_V5 - auto_close */;
            return _toStringbool(
                &m->nested.multisig_create_or_approve_proposal_as_identity_V5.auto_close,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_create_or_approve_proposal_as_key_V5 - multisig */;
            return _toStringAccountId_V5(
                &m->nested.multisig_create_or_approve_proposal_as_key_V5.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_create_or_approve_proposal_as_key_V5 - proposal */;
            return _toStringProposal(
                &m->nested.multisig_create_or_approve_proposal_as_key_V5.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_create_or_approve_proposal_as_key_V5 - expiry */;
            return _toStringOptionMoment_V5(
                &m->nested.multisig_create_or_approve_proposal_as_key_V5.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_create_or_approve_proposal_as_key_V5 - auto_close */;
            return _toStringbool(
                &m->nested.multisig_create_or_approve_proposal_as_key_V5.auto_close,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_create_proposal_as_identity_V5 - multisig */;
            return _toStringAccountId_V5(
                &m->nested.multisig_create_proposal_as_identity_V5.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_create_proposal_as_identity_V5 - proposal */;
            return _toStringProposal(
                &m->nested.multisig_create_proposal_as_identity_V5.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_create_proposal_as_identity_V5 - expiry */;
            return _toStringOptionMoment_V5(
                &m->nested.multisig_create_proposal_as_identity_V5.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_create_proposal_as_identity_V5 - auto_close */;
            return _toStringbool(
                &m->nested.multisig_create_proposal_as_identity_V5.auto_close,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0: /* multisig_create_proposal_as_key_V5 - multisig */;
            return _toStringAccountId_V5(
                &m->nested.multisig_create_proposal_as_key_V5.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_create_proposal_as_key_V5 - proposal */;
            return _toStringProposal(
                &m->nested.multisig_create_proposal_as_key_V5.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_create_proposal_as_key_V5 - expiry */;
            return _toStringOptionMoment_V5(
                &m->nested.multisig_create_proposal_as_key_V5.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_create_proposal_as_key_V5 - auto_close */;
            return _toStringbool(
                &m->nested.multisig_create_proposal_as_key_V5.auto_close,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4613: /* module 18 call 5 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_identity_V5 - multisig */;
            return _toStringAccountId_V5(
                &m->basic.multisig_approve_as_identity_V5.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_identity_V5 - proposal_id */;
            return _toStringu64(
                &m->basic.multisig_approve_as_identity_V5.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4614: /* module 18 call 6 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_key_V5 - multisig */;
            return _toStringAccountId_V5(
                &m->basic.multisig_approve_as_key_V5.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_key_V5 - proposal_id */;
            return _toStringu64(
                &m->basic.multisig_approve_as_key_V5.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4615: /* module 18 call 7 */
        switch (itemIdx) {
        case 0: /* multisig_reject_as_identity_V5 - multisig */;
            return _toStringAccountId_V5(
                &m->basic.multisig_reject_as_identity_V5.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_reject_as_identity_V5 - proposal_id */;
            return _toStringu64(
                &m->basic.multisig_reject_as_identity_V5.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4616: /* module 18 call 8 */
        switch (itemIdx) {
        case 0: /* multisig_reject_as_key_V5 - multisig */;
            return _toStringAccountId_V5(
                &m->basic.multisig_reject_as_key_V5.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_reject_as_key_V5 - proposal_id */;
            return _toStringu64(
                &m->basic.multisig_reject_as_key_V5.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4617: /* module 18 call 9 */
        switch (itemIdx) {
        case 0: /* multisig_accept_multisig_signer_as_identity_V5 - auth_id */;
            return _toStringu64(
                &m->basic.multisig_accept_multisig_signer_as_identity_V5.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4618: /* module 18 call 10 */
        switch (itemIdx) {
        case 0: /* multisig_accept_multisig_signer_as_key_V5 - auth_id */;
            return _toStringu64(
                &m->basic.multisig_accept_multisig_signer_as_key_V5.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4619: /* module 18 call 11 */
        switch (itemIdx) {
        case 0: /* multisig_add_multisig_signer_V5 - signer */;
            return _toStringSignatory_V5(
                &m->basic.multisig_add_multisig_signer_V5.signer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4620: /* module 18 call 12 */
        switch (itemIdx) {
        case 0: /* multisig_remove_multisig_signer_V5 - signer */;
            return _toStringSignatory_V5(
                &m->basic.multisig_remove_multisig_signer_V5.signer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4621: /* module 18 call 13 */
        switch (itemIdx) {
        case 0: /* multisig_add_multisig_signers_via_creator_V5 - multisig */;
            return _toStringAccountId_V5(
                &m->basic.multisig_add_multisig_signers_via_creator_V5.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_add_multisig_signers_via_creator_V5 - signers */;
            return _toStringVecSignatory_V5(
                &m->basic.multisig_add_multisig_signers_via_creator_V5.signers,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4622: /* module 18 call 14 */
        switch (itemIdx) {
        case 0: /* multisig_remove_multisig_signers_via_creator_V5 - multisig */;
            return _toStringAccountId_V5(
                &m->basic.multisig_remove_multisig_signers_via_creator_V5.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_remove_multisig_signers_via_creator_V5 - signers */;
            return _toStringVecSignatory_V5(
                &m->basic.multisig_remove_multisig_signers_via_creator_V5.signers,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4623: /* module 18 call 15 */
        switch (itemIdx) {
        case 0: /* multisig_change_sigs_required_V5 - sigs_required */;
            return _toStringu64(
                &m->basic.multisig_change_sigs_required_V5.sigs_required,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4624: /* module 18 call 16 */
        switch (itemIdx) {
        case 0: /* multisig_make_multisig_signer_V5 - multisig */;
            return _toStringAccountId_V5(
                &m->basic.multisig_make_multisig_signer_V5.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4625: /* module 18 call 17 */
        switch (itemIdx) {
        case 0: /* multisig_make_multisig_primary_V5 - multisig */;
            return _toStringAccountId_V5(
                &m->basic.multisig_make_multisig_primary_V5.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_make_multisig_primary_V5 - optional_cdd_auth_id */;
            return _toStringOptionu64(
                &m->basic.multisig_make_multisig_primary_V5.optional_cdd_auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4626: /* module 18 call 18 */
        switch (itemIdx) {
        case 0: /* multisig_execute_scheduled_proposal_V5 - multisig */;
            return _toStringAccountId_V5(
                &m->basic.multisig_execute_scheduled_proposal_V5.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_execute_scheduled_proposal_V5 - proposal_id */;
            return _toStringu64(
                &m->basic.multisig_execute_scheduled_proposal_V5.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_execute_scheduled_proposal_V5 - multisig_did */;
            return _toStringIdentityId_V5(
                &m->basic.multisig_execute_scheduled_proposal_V5.multisig_did,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_execute_scheduled_proposal_V5 - proposal_weight */;
            return _toStringWeight_V5(
                &m->basic.multisig_execute_scheduled_proposal_V5.proposal_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5120: /* module 20 call 0 */
        switch (itemIdx) {
        case 0: /* contracts_update_schedule_V5 - schedule */;
            return _toStringSchedule_V5(
                &m->basic.contracts_update_schedule_V5.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5121: /* module 20 call 1 */
        switch (itemIdx) {
        case 0: /* contracts_put_code_V5 - meta_info */;
            return _toStringTemplateMetadata_V5(
                &m->basic.contracts_put_code_V5.meta_info,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_put_code_V5 - instantiation_fee */;
            return _toStringBalanceOf(
                &m->basic.contracts_put_code_V5.instantiation_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_put_code_V5 - code */;
            return _toStringBytes(
                &m->basic.contracts_put_code_V5.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5122: /* module 20 call 2 */
        switch (itemIdx) {
        case 0: /* contracts_call_V5 - dest */;
            return _toStringLookupSource(
                &m->basic.contracts_call_V5.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_call_V5 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.contracts_call_V5.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_call_V5 - gas_limit */;
            return _toStringCompactGas_V5(
                &m->basic.contracts_call_V5.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_call_V5 - data */;
            return _toStringBytes(
                &m->basic.contracts_call_V5.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5123: /* module 20 call 3 */
        switch (itemIdx) {
        case 0: /* contracts_instantiate_V5 - endowment */;
            return _toStringCompactBalanceOf(
                &m->basic.contracts_instantiate_V5.endowment,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_instantiate_V5 - gas_limit */;
            return _toStringCompactGas_V5(
                &m->basic.contracts_instantiate_V5.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_instantiate_V5 - code_hash */;
            return _toStringCodeHash_V5(
                &m->basic.contracts_instantiate_V5.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_instantiate_V5 - data */;
            return _toStringBytes(
                &m->basic.contracts_instantiate_V5.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_instantiate_V5 - max_fee */;
            return _toStringBalanceOf(
                &m->basic.contracts_instantiate_V5.max_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5124: /* module 20 call 4 */
        switch (itemIdx) {
        case 0: /* contracts_freeze_instantiation_V5 - code_hash */;
            return _toStringCodeHash_V5(
                &m->basic.contracts_freeze_instantiation_V5.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5125: /* module 20 call 5 */
        switch (itemIdx) {
        case 0: /* contracts_unfreeze_instantiation_V5 - code_hash */;
            return _toStringCodeHash_V5(
                &m->basic.contracts_unfreeze_instantiation_V5.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5126: /* module 20 call 6 */
        switch (itemIdx) {
        case 0: /* contracts_transfer_template_ownership_V5 - code_hash */;
            return _toStringCodeHash_V5(
                &m->basic.contracts_transfer_template_ownership_V5.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_transfer_template_ownership_V5 - new_owner */;
            return _toStringIdentityId_V5(
                &m->basic.contracts_transfer_template_ownership_V5.new_owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5127: /* module 20 call 7 */
        switch (itemIdx) {
        case 0: /* contracts_change_template_fees_V5 - code_hash */;
            return _toStringCodeHash_V5(
                &m->basic.contracts_change_template_fees_V5.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_change_template_fees_V5 - new_instantiation_fee */;
            return _toStringOptionBalanceOf(
                &m->basic.contracts_change_template_fees_V5.new_instantiation_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_change_template_fees_V5 - new_usage_fee */;
            return _toStringOptionBalanceOf(
                &m->basic.contracts_change_template_fees_V5.new_usage_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5128: /* module 20 call 8 */
        switch (itemIdx) {
        case 0: /* contracts_change_template_meta_url_V5 - code_hash */;
            return _toStringCodeHash_V5(
                &m->basic.contracts_change_template_meta_url_V5.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_change_template_meta_url_V5 - new_url */;
            return _toStringOptionMetaUrl_V5(
                &m->basic.contracts_change_template_meta_url_V5.new_url,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0: /* treasury_disbursement_V5 - beneficiaries */;
            return _toStringVecBeneficiary_V5(
                &m->basic.treasury_disbursement_V5.beneficiaries,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5377: /* module 21 call 1 */
        switch (itemIdx) {
        case 0: /* treasury_reimbursement_V5 - amount */;
            return _toStringBalanceOf(
                &m->basic.treasury_reimbursement_V5.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5632: /* module 22 call 0 */
        switch (itemIdx) {
        case 0: /* polymeshcommittee_set_vote_threshold_V5 - n */;
            return _toStringu32(
                &m->basic.polymeshcommittee_set_vote_threshold_V5.n,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polymeshcommittee_set_vote_threshold_V5 - d */;
            return _toStringu32(
                &m->basic.polymeshcommittee_set_vote_threshold_V5.d,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5633: /* module 22 call 1 */
        switch (itemIdx) {
        case 0: /* polymeshcommittee_set_release_coordinator_V5 - id */;
            return _toStringIdentityId_V5(
                &m->basic.polymeshcommittee_set_release_coordinator_V5.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5634: /* module 22 call 2 */
        switch (itemIdx) {
        case 0: /* polymeshcommittee_set_expires_after_V5 - expiry */;
            return _toStringMaybeBlock_V5(
                &m->basic.polymeshcommittee_set_expires_after_V5.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5635: /* module 22 call 3 */
        switch (itemIdx) {
        case 0: /* polymeshcommittee_vote_or_propose_V5 - approve */;
            return _toStringbool(
                &m->nested.polymeshcommittee_vote_or_propose_V5.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polymeshcommittee_vote_or_propose_V5 - call */;
            return _toStringProposal(
                &m->nested.polymeshcommittee_vote_or_propose_V5.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5636: /* module 22 call 4 */
        switch (itemIdx) {
        case 0: /* polymeshcommittee_vote_V5 - proposal */;
            return _toStringHash(
                &m->basic.polymeshcommittee_vote_V5.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polymeshcommittee_vote_V5 - index */;
            return _toStringProposalIndex_V5(
                &m->basic.polymeshcommittee_vote_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* polymeshcommittee_vote_V5 - approve */;
            return _toStringbool(
                &m->basic.polymeshcommittee_vote_V5.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        case 0: /* committeemembership_set_active_members_limit_V5 - limit */;
            return _toStringMemberCount_V5(
                &m->basic.committeemembership_set_active_members_limit_V5.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5889: /* module 23 call 1 */
        switch (itemIdx) {
        case 0: /* committeemembership_disable_member_V5 - who */;
            return _toStringIdentityId_V5(
                &m->basic.committeemembership_disable_member_V5.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* committeemembership_disable_member_V5 - expiry */;
            return _toStringOptionMoment_V5(
                &m->basic.committeemembership_disable_member_V5.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* committeemembership_disable_member_V5 - at */;
            return _toStringOptionMoment_V5(
                &m->basic.committeemembership_disable_member_V5.at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5890: /* module 23 call 2 */
        switch (itemIdx) {
        case 0: /* committeemembership_add_member_V5 - who */;
            return _toStringIdentityId_V5(
                &m->basic.committeemembership_add_member_V5.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5891: /* module 23 call 3 */
        switch (itemIdx) {
        case 0: /* committeemembership_remove_member_V5 - who */;
            return _toStringIdentityId_V5(
                &m->basic.committeemembership_remove_member_V5.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5892: /* module 23 call 4 */
        switch (itemIdx) {
        case 0: /* committeemembership_swap_member_V5 - remove */;
            return _toStringIdentityId_V5(
                &m->basic.committeemembership_swap_member_V5.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* committeemembership_swap_member_V5 - add */;
            return _toStringIdentityId_V5(
                &m->basic.committeemembership_swap_member_V5.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5893: /* module 23 call 5 */
        switch (itemIdx) {
        case 0: /* committeemembership_reset_members_V5 - members */;
            return _toStringVecIdentityId_V5(
                &m->basic.committeemembership_reset_members_V5.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5894: /* module 23 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0: /* pips_set_prune_historical_pips_V5 - prune */;
            return _toStringbool(
                &m->basic.pips_set_prune_historical_pips_V5.prune,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6145: /* module 24 call 1 */
        switch (itemIdx) {
        case 0: /* pips_set_min_proposal_deposit_V5 - deposit */;
            return _toStringBalanceOf(
                &m->basic.pips_set_min_proposal_deposit_V5.deposit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0: /* pips_set_default_enactment_period_V5 - duration */;
            return _toStringBlockNumber(
                &m->basic.pips_set_default_enactment_period_V5.duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6147: /* module 24 call 3 */
        switch (itemIdx) {
        case 0: /* pips_set_pending_pip_expiry_V5 - expiry */;
            return _toStringMaybeBlock_V5(
                &m->basic.pips_set_pending_pip_expiry_V5.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0: /* pips_set_max_pip_skip_count_V5 - max */;
            return _toStringSkippedCount_V5(
                &m->basic.pips_set_max_pip_skip_count_V5.max,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6149: /* module 24 call 5 */
        switch (itemIdx) {
        case 0: /* pips_set_active_pip_limit_V5 - limit */;
            return _toStringu32(
                &m->basic.pips_set_active_pip_limit_V5.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6150: /* module 24 call 6 */
        switch (itemIdx) {
        case 0: /* pips_propose_V5 - proposal */;
            return _toStringProposal(
                &m->nested.pips_propose_V5.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pips_propose_V5 - deposit */;
            return _toStringBalanceOf(
                &m->nested.pips_propose_V5.deposit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* pips_propose_V5 - url */;
            return _toStringOptionUrl_V5(
                &m->nested.pips_propose_V5.url,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* pips_propose_V5 - description */;
            return _toStringOptionPipDescription_V5(
                &m->nested.pips_propose_V5.description,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6151: /* module 24 call 7 */
        switch (itemIdx) {
        case 0: /* pips_vote_V5 - id */;
            return _toStringPipId_V5(
                &m->basic.pips_vote_V5.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pips_vote_V5 - aye_or_nay */;
            return _toStringbool(
                &m->basic.pips_vote_V5.aye_or_nay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* pips_vote_V5 - deposit */;
            return _toStringBalanceOf(
                &m->basic.pips_vote_V5.deposit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6152: /* module 24 call 8 */
        switch (itemIdx) {
        case 0: /* pips_approve_committee_proposal_V5 - id */;
            return _toStringPipId_V5(
                &m->basic.pips_approve_committee_proposal_V5.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6153: /* module 24 call 9 */
        switch (itemIdx) {
        case 0: /* pips_reject_proposal_V5 - id */;
            return _toStringPipId_V5(
                &m->basic.pips_reject_proposal_V5.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6154: /* module 24 call 10 */
        switch (itemIdx) {
        case 0: /* pips_prune_proposal_V5 - id */;
            return _toStringPipId_V5(
                &m->basic.pips_prune_proposal_V5.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6155: /* module 24 call 11 */
        switch (itemIdx) {
        case 0: /* pips_reschedule_execution_V5 - id */;
            return _toStringPipId_V5(
                &m->basic.pips_reschedule_execution_V5.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pips_reschedule_execution_V5 - until */;
            return _toStringOptionBlockNumber(
                &m->basic.pips_reschedule_execution_V5.until,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6156: /* module 24 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6157: /* module 24 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6158: /* module 24 call 14 */
        switch (itemIdx) {
        case 0: /* pips_enact_snapshot_results_V5 - results */;
            return _toStringVecTuplePipIdSnapshotResult_V5(
                &m->basic.pips_enact_snapshot_results_V5.results,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6159: /* module 24 call 15 */
        switch (itemIdx) {
        case 0: /* pips_execute_scheduled_pip_V5 - id */;
            return _toStringPipId_V5(
                &m->basic.pips_execute_scheduled_pip_V5.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6160: /* module 24 call 16 */
        switch (itemIdx) {
        case 0: /* pips_expire_scheduled_pip_V5 - did */;
            return _toStringIdentityId_V5(
                &m->basic.pips_expire_scheduled_pip_V5.did,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pips_expire_scheduled_pip_V5 - id */;
            return _toStringPipId_V5(
                &m->basic.pips_expire_scheduled_pip_V5.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_vote_threshold_V5 - n */;
            return _toStringu32(
                &m->basic.technicalcommittee_set_vote_threshold_V5.n,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_set_vote_threshold_V5 - d */;
            return _toStringu32(
                &m->basic.technicalcommittee_set_vote_threshold_V5.d,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_release_coordinator_V5 - id */;
            return _toStringIdentityId_V5(
                &m->basic.technicalcommittee_set_release_coordinator_V5.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_expires_after_V5 - expiry */;
            return _toStringMaybeBlock_V5(
                &m->basic.technicalcommittee_set_expires_after_V5.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_vote_or_propose_V5 - approve */;
            return _toStringbool(
                &m->nested.technicalcommittee_vote_or_propose_V5.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_vote_or_propose_V5 - call */;
            return _toStringProposal(
                &m->nested.technicalcommittee_vote_or_propose_V5.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6404: /* module 25 call 4 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_vote_V5 - proposal */;
            return _toStringHash(
                &m->basic.technicalcommittee_vote_V5.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_vote_V5 - index */;
            return _toStringProposalIndex_V5(
                &m->basic.technicalcommittee_vote_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_vote_V5 - approve */;
            return _toStringbool(
                &m->basic.technicalcommittee_vote_V5.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_set_active_members_limit_V5 - limit */;
            return _toStringMemberCount_V5(
                &m->basic.technicalcommitteemembership_set_active_members_limit_V5.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_disable_member_V5 - who */;
            return _toStringIdentityId_V5(
                &m->basic.technicalcommitteemembership_disable_member_V5.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommitteemembership_disable_member_V5 - expiry */;
            return _toStringOptionMoment_V5(
                &m->basic.technicalcommitteemembership_disable_member_V5.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommitteemembership_disable_member_V5 - at */;
            return _toStringOptionMoment_V5(
                &m->basic.technicalcommitteemembership_disable_member_V5.at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_add_member_V5 - who */;
            return _toStringIdentityId_V5(
                &m->basic.technicalcommitteemembership_add_member_V5.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_remove_member_V5 - who */;
            return _toStringIdentityId_V5(
                &m->basic.technicalcommitteemembership_remove_member_V5.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_swap_member_V5 - remove */;
            return _toStringIdentityId_V5(
                &m->basic.technicalcommitteemembership_swap_member_V5.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommitteemembership_swap_member_V5 - add */;
            return _toStringIdentityId_V5(
                &m->basic.technicalcommitteemembership_swap_member_V5.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_reset_members_V5 - members */;
            return _toStringVecIdentityId_V5(
                &m->basic.technicalcommitteemembership_reset_members_V5.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6662: /* module 26 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0: /* upgradecommittee_set_vote_threshold_V5 - n */;
            return _toStringu32(
                &m->basic.upgradecommittee_set_vote_threshold_V5.n,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* upgradecommittee_set_vote_threshold_V5 - d */;
            return _toStringu32(
                &m->basic.upgradecommittee_set_vote_threshold_V5.d,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0: /* upgradecommittee_set_release_coordinator_V5 - id */;
            return _toStringIdentityId_V5(
                &m->basic.upgradecommittee_set_release_coordinator_V5.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0: /* upgradecommittee_set_expires_after_V5 - expiry */;
            return _toStringMaybeBlock_V5(
                &m->basic.upgradecommittee_set_expires_after_V5.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0: /* upgradecommittee_vote_or_propose_V5 - approve */;
            return _toStringbool(
                &m->nested.upgradecommittee_vote_or_propose_V5.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* upgradecommittee_vote_or_propose_V5 - call */;
            return _toStringProposal(
                &m->nested.upgradecommittee_vote_or_propose_V5.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0: /* upgradecommittee_vote_V5 - proposal */;
            return _toStringHash(
                &m->basic.upgradecommittee_vote_V5.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* upgradecommittee_vote_V5 - index */;
            return _toStringProposalIndex_V5(
                &m->basic.upgradecommittee_vote_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* upgradecommittee_vote_V5 - approve */;
            return _toStringbool(
                &m->basic.upgradecommittee_vote_V5.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_set_active_members_limit_V5 - limit */;
            return _toStringMemberCount_V5(
                &m->basic.upgradecommitteemembership_set_active_members_limit_V5.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_disable_member_V5 - who */;
            return _toStringIdentityId_V5(
                &m->basic.upgradecommitteemembership_disable_member_V5.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* upgradecommitteemembership_disable_member_V5 - expiry */;
            return _toStringOptionMoment_V5(
                &m->basic.upgradecommitteemembership_disable_member_V5.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* upgradecommitteemembership_disable_member_V5 - at */;
            return _toStringOptionMoment_V5(
                &m->basic.upgradecommitteemembership_disable_member_V5.at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_add_member_V5 - who */;
            return _toStringIdentityId_V5(
                &m->basic.upgradecommitteemembership_add_member_V5.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_remove_member_V5 - who */;
            return _toStringIdentityId_V5(
                &m->basic.upgradecommitteemembership_remove_member_V5.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7172: /* module 28 call 4 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_swap_member_V5 - remove */;
            return _toStringIdentityId_V5(
                &m->basic.upgradecommitteemembership_swap_member_V5.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* upgradecommitteemembership_swap_member_V5 - add */;
            return _toStringIdentityId_V5(
                &m->basic.upgradecommitteemembership_swap_member_V5.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7173: /* module 28 call 5 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_reset_members_V5 - members */;
            return _toStringVecIdentityId_V5(
                &m->basic.upgradecommitteemembership_reset_members_V5.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7174: /* module 28 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0: /* asset_register_ticker_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.asset_register_ticker_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0: /* asset_accept_ticker_transfer_V5 - auth_id */;
            return _toStringu64(
                &m->basic.asset_accept_ticker_transfer_V5.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0: /* asset_accept_primary_issuance_agent_transfer_V5 - auth_id */;
            return _toStringu64(
                &m->basic.asset_accept_primary_issuance_agent_transfer_V5.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        case 0: /* asset_accept_asset_ownership_transfer_V5 - auth_id */;
            return _toStringu64(
                &m->basic.asset_accept_asset_ownership_transfer_V5.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7428: /* module 29 call 4 */
        switch (itemIdx) {
        case 0: /* asset_create_asset_V5 - name */;
            return _toStringAssetName_V5(
                &m->basic.asset_create_asset_V5.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_create_asset_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.asset_create_asset_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* asset_create_asset_V5 - total_supply */;
            return _toStringBalance(
                &m->basic.asset_create_asset_V5.total_supply,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* asset_create_asset_V5 - divisible */;
            return _toStringbool(
                &m->basic.asset_create_asset_V5.divisible,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* asset_create_asset_V5 - asset_type */;
            return _toStringAssetType_V5(
                &m->basic.asset_create_asset_V5.asset_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* asset_create_asset_V5 - identifiers */;
            return _toStringVecAssetIdentifier_V5(
                &m->basic.asset_create_asset_V5.identifiers,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* asset_create_asset_V5 - funding_round */;
            return _toStringOptionFundingRoundName_V5(
                &m->basic.asset_create_asset_V5.funding_round,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7429: /* module 29 call 5 */
        switch (itemIdx) {
        case 0: /* asset_freeze_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.asset_freeze_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7430: /* module 29 call 6 */
        switch (itemIdx) {
        case 0: /* asset_unfreeze_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.asset_unfreeze_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7431: /* module 29 call 7 */
        switch (itemIdx) {
        case 0: /* asset_rename_asset_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.asset_rename_asset_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_rename_asset_V5 - name */;
            return _toStringAssetName_V5(
                &m->basic.asset_rename_asset_V5.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7432: /* module 29 call 8 */
        switch (itemIdx) {
        case 0: /* asset_issue_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.asset_issue_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_issue_V5 - value */;
            return _toStringBalance(
                &m->basic.asset_issue_V5.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7433: /* module 29 call 9 */
        switch (itemIdx) {
        case 0: /* asset_redeem_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.asset_redeem_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_redeem_V5 - value */;
            return _toStringBalance(
                &m->basic.asset_redeem_V5.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7434: /* module 29 call 10 */
        switch (itemIdx) {
        case 0: /* asset_make_divisible_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.asset_make_divisible_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7435: /* module 29 call 11 */
        switch (itemIdx) {
        case 0: /* asset_add_documents_V5 - docs */;
            return _toStringVecDocument_V5(
                &m->basic.asset_add_documents_V5.docs,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_add_documents_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.asset_add_documents_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7436: /* module 29 call 12 */
        switch (itemIdx) {
        case 0: /* asset_remove_documents_V5 - ids */;
            return _toStringVecDocumentId_V5(
                &m->basic.asset_remove_documents_V5.ids,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_remove_documents_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.asset_remove_documents_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7437: /* module 29 call 13 */
        switch (itemIdx) {
        case 0: /* asset_set_funding_round_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.asset_set_funding_round_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_set_funding_round_V5 - name */;
            return _toStringFundingRoundName_V5(
                &m->basic.asset_set_funding_round_V5.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7438: /* module 29 call 14 */
        switch (itemIdx) {
        case 0: /* asset_update_identifiers_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.asset_update_identifiers_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_update_identifiers_V5 - identifiers */;
            return _toStringVecAssetIdentifier_V5(
                &m->basic.asset_update_identifiers_V5.identifiers,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7439: /* module 29 call 15 */
        switch (itemIdx) {
        case 0: /* asset_add_extension_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.asset_add_extension_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_add_extension_V5 - extension_details */;
            return _toStringSmartExtension_V5(
                &m->basic.asset_add_extension_V5.extension_details,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7440: /* module 29 call 16 */
        switch (itemIdx) {
        case 0: /* asset_archive_extension_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.asset_archive_extension_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_archive_extension_V5 - extension_id */;
            return _toStringAccountId_V5(
                &m->basic.asset_archive_extension_V5.extension_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7441: /* module 29 call 17 */
        switch (itemIdx) {
        case 0: /* asset_unarchive_extension_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.asset_unarchive_extension_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_unarchive_extension_V5 - extension_id */;
            return _toStringAccountId_V5(
                &m->basic.asset_unarchive_extension_V5.extension_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7442: /* module 29 call 18 */
        switch (itemIdx) {
        case 0: /* asset_remove_primary_issuance_agent_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.asset_remove_primary_issuance_agent_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7443: /* module 29 call 19 */
        switch (itemIdx) {
        case 0: /* asset_remove_smart_extension_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.asset_remove_smart_extension_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_remove_smart_extension_V5 - extension_id */;
            return _toStringAccountId_V5(
                &m->basic.asset_remove_smart_extension_V5.extension_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7444: /* module 29 call 20 */
        switch (itemIdx) {
        case 0: /* asset_claim_classic_ticker_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.asset_claim_classic_ticker_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_claim_classic_ticker_V5 - ethereum_signature */;
            return _toStringEcdsaSignature_V5(
                &m->basic.asset_claim_classic_ticker_V5.ethereum_signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7445: /* module 29 call 21 */
        switch (itemIdx) {
        case 0: /* asset_reserve_classic_ticker_V5 - classic_ticker_import */;
            return _toStringClassicTickerImport_V5(
                &m->basic.asset_reserve_classic_ticker_V5.classic_ticker_import,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_reserve_classic_ticker_V5 - contract_did */;
            return _toStringIdentityId_V5(
                &m->basic.asset_reserve_classic_ticker_V5.contract_did,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* asset_reserve_classic_ticker_V5 - config */;
            return _toStringTickerRegistrationConfig_V5(
                &m->basic.asset_reserve_classic_ticker_V5.config,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0: /* bridge_change_controller_V5 - controller */;
            return _toStringAccountId_V5(
                &m->basic.bridge_change_controller_V5.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0: /* bridge_change_admin_V5 - admin */;
            return _toStringAccountId_V5(
                &m->basic.bridge_change_admin_V5.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0: /* bridge_change_timelock_V5 - timelock */;
            return _toStringBlockNumber(
                &m->basic.bridge_change_timelock_V5.timelock,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7940: /* module 31 call 4 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7941: /* module 31 call 5 */
        switch (itemIdx) {
        case 0: /* bridge_change_bridge_limit_V5 - amount */;
            return _toStringBalance(
                &m->basic.bridge_change_bridge_limit_V5.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bridge_change_bridge_limit_V5 - duration */;
            return _toStringBlockNumber(
                &m->basic.bridge_change_bridge_limit_V5.duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7942: /* module 31 call 6 */
        switch (itemIdx) {
        case 0: /* bridge_change_bridge_exempted_V5 - exempted */;
            return _toStringVecTupleIdentityIdbool_V5(
                &m->basic.bridge_change_bridge_exempted_V5.exempted,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7943: /* module 31 call 7 */
        switch (itemIdx) {
        case 0: /* bridge_force_handle_bridge_tx_V5 - bridge_tx */;
            return _toStringBridgeTx_V5(
                &m->basic.bridge_force_handle_bridge_tx_V5.bridge_tx,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7944: /* module 31 call 8 */
        switch (itemIdx) {
        case 0: /* bridge_batch_propose_bridge_tx_V5 - bridge_txs */;
            return _toStringVecBridgeTx_V5(
                &m->basic.bridge_batch_propose_bridge_tx_V5.bridge_txs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7945: /* module 31 call 9 */
        switch (itemIdx) {
        case 0: /* bridge_propose_bridge_tx_V5 - bridge_tx */;
            return _toStringBridgeTx_V5(
                &m->basic.bridge_propose_bridge_tx_V5.bridge_tx,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7946: /* module 31 call 10 */
        switch (itemIdx) {
        case 0: /* bridge_handle_bridge_tx_V5 - bridge_tx */;
            return _toStringBridgeTx_V5(
                &m->basic.bridge_handle_bridge_tx_V5.bridge_tx,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7947: /* module 31 call 11 */
        switch (itemIdx) {
        case 0: /* bridge_freeze_txs_V5 - bridge_txs */;
            return _toStringVecBridgeTx_V5(
                &m->basic.bridge_freeze_txs_V5.bridge_txs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7948: /* module 31 call 12 */
        switch (itemIdx) {
        case 0: /* bridge_unfreeze_txs_V5 - bridge_txs */;
            return _toStringVecBridgeTx_V5(
                &m->basic.bridge_unfreeze_txs_V5.bridge_txs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7949: /* module 31 call 13 */
        switch (itemIdx) {
        case 0: /* bridge_handle_scheduled_bridge_tx_V5 - bridge_tx */;
            return _toStringBridgeTx_V5(
                &m->basic.bridge_handle_scheduled_bridge_tx_V5.bridge_tx,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        case 0: /* compliancemanager_add_compliance_requirement_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.compliancemanager_add_compliance_requirement_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_add_compliance_requirement_V5 - sender_conditions */;
            return _toStringVecCondition_V5(
                &m->basic.compliancemanager_add_compliance_requirement_V5.sender_conditions,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* compliancemanager_add_compliance_requirement_V5 - receiver_conditions */;
            return _toStringVecCondition_V5(
                &m->basic.compliancemanager_add_compliance_requirement_V5.receiver_conditions,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        case 0: /* compliancemanager_remove_compliance_requirement_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.compliancemanager_remove_compliance_requirement_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_remove_compliance_requirement_V5 - id */;
            return _toStringu32(
                &m->basic.compliancemanager_remove_compliance_requirement_V5.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8194: /* module 32 call 2 */
        switch (itemIdx) {
        case 0: /* compliancemanager_replace_asset_compliance_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.compliancemanager_replace_asset_compliance_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_replace_asset_compliance_V5 - asset_compliance */;
            return _toStringVecComplianceRequirement_V5(
                &m->basic.compliancemanager_replace_asset_compliance_V5.asset_compliance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8195: /* module 32 call 3 */
        switch (itemIdx) {
        case 0: /* compliancemanager_reset_asset_compliance_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.compliancemanager_reset_asset_compliance_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8196: /* module 32 call 4 */
        switch (itemIdx) {
        case 0: /* compliancemanager_pause_asset_compliance_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.compliancemanager_pause_asset_compliance_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8197: /* module 32 call 5 */
        switch (itemIdx) {
        case 0: /* compliancemanager_resume_asset_compliance_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.compliancemanager_resume_asset_compliance_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8198: /* module 32 call 6 */
        switch (itemIdx) {
        case 0: /* compliancemanager_add_default_trusted_claim_issuer_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.compliancemanager_add_default_trusted_claim_issuer_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_add_default_trusted_claim_issuer_V5 - issuer */;
            return _toStringTrustedIssuer_V5(
                &m->basic.compliancemanager_add_default_trusted_claim_issuer_V5.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8199: /* module 32 call 7 */
        switch (itemIdx) {
        case 0: /* compliancemanager_remove_default_trusted_claim_issuer_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.compliancemanager_remove_default_trusted_claim_issuer_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_remove_default_trusted_claim_issuer_V5 - issuer */;
            return _toStringIdentityId_V5(
                &m->basic.compliancemanager_remove_default_trusted_claim_issuer_V5.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8200: /* module 32 call 8 */
        switch (itemIdx) {
        case 0: /* compliancemanager_change_compliance_requirement_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.compliancemanager_change_compliance_requirement_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_change_compliance_requirement_V5 - new_req */;
            return _toStringComplianceRequirement_V5(
                &m->basic.compliancemanager_change_compliance_requirement_V5.new_req,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9216: /* module 36 call 0 */
        switch (itemIdx) {
        case 0: /* settlement_create_venue_V5 - details */;
            return _toStringVenueDetails_V5(
                &m->basic.settlement_create_venue_V5.details,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_create_venue_V5 - signers */;
            return _toStringVecAccountId_V5(
                &m->basic.settlement_create_venue_V5.signers,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_create_venue_V5 - venue_type */;
            return _toStringVenueType_V5(
                &m->basic.settlement_create_venue_V5.venue_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9217: /* module 36 call 1 */
        switch (itemIdx) {
        case 0: /* settlement_update_venue_V5 - venue_id */;
            return _toStringu64(
                &m->basic.settlement_update_venue_V5.venue_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_update_venue_V5 - details */;
            return _toStringOptionVenueDetails_V5(
                &m->basic.settlement_update_venue_V5.details,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_update_venue_V5 - typ */;
            return _toStringOptionVenueType_V5(
                &m->basic.settlement_update_venue_V5.typ,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9218: /* module 36 call 2 */
        switch (itemIdx) {
        case 0: /* settlement_add_instruction_V5 - venue_id */;
            return _toStringu64(
                &m->basic.settlement_add_instruction_V5.venue_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_add_instruction_V5 - settlement_type */;
            return _toStringSettlementType_V5(
                &m->basic.settlement_add_instruction_V5.settlement_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_add_instruction_V5 - trade_date */;
            return _toStringOptionMoment_V5(
                &m->basic.settlement_add_instruction_V5.trade_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* settlement_add_instruction_V5 - value_date */;
            return _toStringOptionMoment_V5(
                &m->basic.settlement_add_instruction_V5.value_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* settlement_add_instruction_V5 - legs */;
            return _toStringVecLeg_V5(
                &m->basic.settlement_add_instruction_V5.legs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9219: /* module 36 call 3 */
        switch (itemIdx) {
        case 0: /* settlement_add_and_affirm_instruction_V5 - venue_id */;
            return _toStringu64(
                &m->basic.settlement_add_and_affirm_instruction_V5.venue_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_add_and_affirm_instruction_V5 - settlement_type */;
            return _toStringSettlementType_V5(
                &m->basic.settlement_add_and_affirm_instruction_V5.settlement_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_add_and_affirm_instruction_V5 - trade_date */;
            return _toStringOptionMoment_V5(
                &m->basic.settlement_add_and_affirm_instruction_V5.trade_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* settlement_add_and_affirm_instruction_V5 - value_date */;
            return _toStringOptionMoment_V5(
                &m->basic.settlement_add_and_affirm_instruction_V5.value_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* settlement_add_and_affirm_instruction_V5 - legs */;
            return _toStringVecLeg_V5(
                &m->basic.settlement_add_and_affirm_instruction_V5.legs,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* settlement_add_and_affirm_instruction_V5 - portfolios */;
            return _toStringVecPortfolioId_V5(
                &m->basic.settlement_add_and_affirm_instruction_V5.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9220: /* module 36 call 4 */
        switch (itemIdx) {
        case 0: /* settlement_affirm_instruction_V5 - instruction_id */;
            return _toStringu64(
                &m->basic.settlement_affirm_instruction_V5.instruction_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_affirm_instruction_V5 - portfolios */;
            return _toStringVecPortfolioId_V5(
                &m->basic.settlement_affirm_instruction_V5.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_affirm_instruction_V5 - max_legs_count */;
            return _toStringu32(
                &m->basic.settlement_affirm_instruction_V5.max_legs_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9221: /* module 36 call 5 */
        switch (itemIdx) {
        case 0: /* settlement_withdraw_affirmation_V5 - instruction_id */;
            return _toStringu64(
                &m->basic.settlement_withdraw_affirmation_V5.instruction_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_withdraw_affirmation_V5 - portfolios */;
            return _toStringVecPortfolioId_V5(
                &m->basic.settlement_withdraw_affirmation_V5.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_withdraw_affirmation_V5 - max_legs_count */;
            return _toStringu32(
                &m->basic.settlement_withdraw_affirmation_V5.max_legs_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9222: /* module 36 call 6 */
        switch (itemIdx) {
        case 0: /* settlement_reject_instruction_V5 - instruction_id */;
            return _toStringu64(
                &m->basic.settlement_reject_instruction_V5.instruction_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_reject_instruction_V5 - portfolios */;
            return _toStringVecPortfolioId_V5(
                &m->basic.settlement_reject_instruction_V5.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_reject_instruction_V5 - max_legs_count */;
            return _toStringu32(
                &m->basic.settlement_reject_instruction_V5.max_legs_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9223: /* module 36 call 7 */
        switch (itemIdx) {
        case 0: /* settlement_affirm_with_receipts_V5 - instruction_id */;
            return _toStringu64(
                &m->basic.settlement_affirm_with_receipts_V5.instruction_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_affirm_with_receipts_V5 - receipt_details */;
            return _toStringVecReceiptDetails_V5(
                &m->basic.settlement_affirm_with_receipts_V5.receipt_details,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_affirm_with_receipts_V5 - portfolios */;
            return _toStringVecPortfolioId_V5(
                &m->basic.settlement_affirm_with_receipts_V5.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* settlement_affirm_with_receipts_V5 - max_legs_count */;
            return _toStringu32(
                &m->basic.settlement_affirm_with_receipts_V5.max_legs_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9224: /* module 36 call 8 */
        switch (itemIdx) {
        case 0: /* settlement_claim_receipt_V5 - instruction_id */;
            return _toStringu64(
                &m->basic.settlement_claim_receipt_V5.instruction_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_claim_receipt_V5 - receipt_details */;
            return _toStringReceiptDetails_V5(
                &m->basic.settlement_claim_receipt_V5.receipt_details,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9225: /* module 36 call 9 */
        switch (itemIdx) {
        case 0: /* settlement_unclaim_receipt_V5 - instruction_id */;
            return _toStringu64(
                &m->basic.settlement_unclaim_receipt_V5.instruction_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_unclaim_receipt_V5 - leg_id */;
            return _toStringu64(
                &m->basic.settlement_unclaim_receipt_V5.leg_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9226: /* module 36 call 10 */
        switch (itemIdx) {
        case 0: /* settlement_set_venue_filtering_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.settlement_set_venue_filtering_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_set_venue_filtering_V5 - enabled */;
            return _toStringbool(
                &m->basic.settlement_set_venue_filtering_V5.enabled,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9227: /* module 36 call 11 */
        switch (itemIdx) {
        case 0: /* settlement_allow_venues_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.settlement_allow_venues_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_allow_venues_V5 - venues */;
            return _toStringVecu64(
                &m->basic.settlement_allow_venues_V5.venues,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9228: /* module 36 call 12 */
        switch (itemIdx) {
        case 0: /* settlement_disallow_venues_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.settlement_disallow_venues_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_disallow_venues_V5 - venues */;
            return _toStringVecu64(
                &m->basic.settlement_disallow_venues_V5.venues,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9229: /* module 36 call 13 */
        switch (itemIdx) {
        case 0: /* settlement_execute_scheduled_instruction_V5 - instruction_id */;
            return _toStringu64(
                &m->basic.settlement_execute_scheduled_instruction_V5.instruction_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_execute_scheduled_instruction_V5 - legs_count */;
            return _toStringu32(
                &m->basic.settlement_execute_scheduled_instruction_V5.legs_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9472: /* module 37 call 0 */
        switch (itemIdx) {
        case 0: /* sto_create_fundraiser_V5 - offering_portfolio */;
            return _toStringPortfolioId_V5(
                &m->basic.sto_create_fundraiser_V5.offering_portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_create_fundraiser_V5 - offering_asset */;
            return _toStringTicker_V5(
                &m->basic.sto_create_fundraiser_V5.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* sto_create_fundraiser_V5 - raising_portfolio */;
            return _toStringPortfolioId_V5(
                &m->basic.sto_create_fundraiser_V5.raising_portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* sto_create_fundraiser_V5 - raising_asset */;
            return _toStringTicker_V5(
                &m->basic.sto_create_fundraiser_V5.raising_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* sto_create_fundraiser_V5 - tiers */;
            return _toStringVecPriceTier_V5(
                &m->basic.sto_create_fundraiser_V5.tiers,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* sto_create_fundraiser_V5 - venue_id */;
            return _toStringu64(
                &m->basic.sto_create_fundraiser_V5.venue_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* sto_create_fundraiser_V5 - start */;
            return _toStringOptionMoment_V5(
                &m->basic.sto_create_fundraiser_V5.start,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 7: /* sto_create_fundraiser_V5 - end */;
            return _toStringOptionMoment_V5(
                &m->basic.sto_create_fundraiser_V5.end,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 8: /* sto_create_fundraiser_V5 - minimum_investment */;
            return _toStringBalance(
                &m->basic.sto_create_fundraiser_V5.minimum_investment,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 9: /* sto_create_fundraiser_V5 - fundraiser_name */;
            return _toStringFundraiserName_V5(
                &m->basic.sto_create_fundraiser_V5.fundraiser_name,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9473: /* module 37 call 1 */
        switch (itemIdx) {
        case 0: /* sto_invest_V5 - investment_portfolio */;
            return _toStringPortfolioId_V5(
                &m->basic.sto_invest_V5.investment_portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_invest_V5 - funding_portfolio */;
            return _toStringPortfolioId_V5(
                &m->basic.sto_invest_V5.funding_portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* sto_invest_V5 - offering_asset */;
            return _toStringTicker_V5(
                &m->basic.sto_invest_V5.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* sto_invest_V5 - fundraiser_id */;
            return _toStringu64(
                &m->basic.sto_invest_V5.fundraiser_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* sto_invest_V5 - investment_amount */;
            return _toStringBalance(
                &m->basic.sto_invest_V5.investment_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* sto_invest_V5 - max_price */;
            return _toStringOptionBalance(
                &m->basic.sto_invest_V5.max_price,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* sto_invest_V5 - receipt */;
            return _toStringOptionReceiptDetails_V5(
                &m->basic.sto_invest_V5.receipt,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9474: /* module 37 call 2 */
        switch (itemIdx) {
        case 0: /* sto_freeze_fundraiser_V5 - offering_asset */;
            return _toStringTicker_V5(
                &m->basic.sto_freeze_fundraiser_V5.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_freeze_fundraiser_V5 - fundraiser_id */;
            return _toStringu64(
                &m->basic.sto_freeze_fundraiser_V5.fundraiser_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9475: /* module 37 call 3 */
        switch (itemIdx) {
        case 0: /* sto_unfreeze_fundraiser_V5 - offering_asset */;
            return _toStringTicker_V5(
                &m->basic.sto_unfreeze_fundraiser_V5.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_unfreeze_fundraiser_V5 - fundraiser_id */;
            return _toStringu64(
                &m->basic.sto_unfreeze_fundraiser_V5.fundraiser_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9476: /* module 37 call 4 */
        switch (itemIdx) {
        case 0: /* sto_modify_fundraiser_window_V5 - offering_asset */;
            return _toStringTicker_V5(
                &m->basic.sto_modify_fundraiser_window_V5.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_modify_fundraiser_window_V5 - fundraiser_id */;
            return _toStringu64(
                &m->basic.sto_modify_fundraiser_window_V5.fundraiser_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* sto_modify_fundraiser_window_V5 - start */;
            return _toStringMoment_V5(
                &m->basic.sto_modify_fundraiser_window_V5.start,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* sto_modify_fundraiser_window_V5 - end */;
            return _toStringOptionMoment_V5(
                &m->basic.sto_modify_fundraiser_window_V5.end,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9477: /* module 37 call 5 */
        switch (itemIdx) {
        case 0: /* sto_stop_V5 - offering_asset */;
            return _toStringTicker_V5(
                &m->basic.sto_stop_V5.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_stop_V5 - fundraiser_id */;
            return _toStringu64(
                &m->basic.sto_stop_V5.fundraiser_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9728: /* module 38 call 0 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_set_active_members_limit_V5 - limit */;
            return _toStringMemberCount_V5(
                &m->basic.cddserviceproviders_set_active_members_limit_V5.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9729: /* module 38 call 1 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_disable_member_V5 - who */;
            return _toStringIdentityId_V5(
                &m->basic.cddserviceproviders_disable_member_V5.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* cddserviceproviders_disable_member_V5 - expiry */;
            return _toStringOptionMoment_V5(
                &m->basic.cddserviceproviders_disable_member_V5.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* cddserviceproviders_disable_member_V5 - at */;
            return _toStringOptionMoment_V5(
                &m->basic.cddserviceproviders_disable_member_V5.at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9730: /* module 38 call 2 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_add_member_V5 - who */;
            return _toStringIdentityId_V5(
                &m->basic.cddserviceproviders_add_member_V5.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9731: /* module 38 call 3 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_remove_member_V5 - who */;
            return _toStringIdentityId_V5(
                &m->basic.cddserviceproviders_remove_member_V5.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9732: /* module 38 call 4 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_swap_member_V5 - remove */;
            return _toStringIdentityId_V5(
                &m->basic.cddserviceproviders_swap_member_V5.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* cddserviceproviders_swap_member_V5 - add */;
            return _toStringIdentityId_V5(
                &m->basic.cddserviceproviders_swap_member_V5.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9733: /* module 38 call 5 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_reset_members_V5 - members */;
            return _toStringVecIdentityId_V5(
                &m->basic.cddserviceproviders_reset_members_V5.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9734: /* module 38 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 9984: /* module 39 call 0 */
        switch (itemIdx) {
        case 0: /* statistics_add_transfer_manager_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.statistics_add_transfer_manager_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* statistics_add_transfer_manager_V5 - new_transfer_manager */;
            return _toStringTransferManager_V5(
                &m->basic.statistics_add_transfer_manager_V5.new_transfer_manager,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9985: /* module 39 call 1 */
        switch (itemIdx) {
        case 0: /* statistics_remove_transfer_manager_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.statistics_remove_transfer_manager_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* statistics_remove_transfer_manager_V5 - transfer_manager */;
            return _toStringTransferManager_V5(
                &m->basic.statistics_remove_transfer_manager_V5.transfer_manager,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9986: /* module 39 call 2 */
        switch (itemIdx) {
        case 0: /* statistics_add_exempted_entities_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.statistics_add_exempted_entities_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* statistics_add_exempted_entities_V5 - transfer_manager */;
            return _toStringTransferManager_V5(
                &m->basic.statistics_add_exempted_entities_V5.transfer_manager,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* statistics_add_exempted_entities_V5 - exempted_entities */;
            return _toStringVecScopeId_V5(
                &m->basic.statistics_add_exempted_entities_V5.exempted_entities,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9987: /* module 39 call 3 */
        switch (itemIdx) {
        case 0: /* statistics_remove_exempted_entities_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.statistics_remove_exempted_entities_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* statistics_remove_exempted_entities_V5 - transfer_manager */;
            return _toStringTransferManager_V5(
                &m->basic.statistics_remove_exempted_entities_V5.transfer_manager,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* statistics_remove_exempted_entities_V5 - entities */;
            return _toStringVecScopeId_V5(
                &m->basic.statistics_remove_exempted_entities_V5.entities,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0: /* protocolfee_change_coefficient_V5 - coefficient */;
            return _toStringPosRatio_V5(
                &m->basic.protocolfee_change_coefficient_V5.coefficient,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10241: /* module 40 call 1 */
        switch (itemIdx) {
        case 0: /* protocolfee_change_base_fee_V5 - op */;
            return _toStringProtocolOp_V5(
                &m->basic.protocolfee_change_base_fee_V5.op,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* protocolfee_change_base_fee_V5 - base_fee */;
            return _toStringBalanceOf(
                &m->basic.protocolfee_change_base_fee_V5.base_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10496: /* module 41 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V5 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V5.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10497: /* module 41 call 1 */
        switch (itemIdx) {
        case 0: /* utility_batch_atomic_V5 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_atomic_V5.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10498: /* module 41 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_optimistic_V5 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_optimistic_V5.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10499: /* module 41 call 3 */
        switch (itemIdx) {
        case 0: /* utility_relay_tx_V5 - target */;
            return _toStringAccountId_V5(
                &m->basic.utility_relay_tx_V5.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_relay_tx_V5 - signature */;
            return _toStringOffChainSignature_V5(
                &m->basic.utility_relay_tx_V5.signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* utility_relay_tx_V5 - call */;
            return _toStringUniqueCall_V5(
                &m->basic.utility_relay_tx_V5.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10752: /* module 42 call 0 */
        switch (itemIdx) {
        case 0: /* portfolio_create_portfolio_V5 - name */;
            return _toStringPortfolioName_V5(
                &m->basic.portfolio_create_portfolio_V5.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10753: /* module 42 call 1 */
        switch (itemIdx) {
        case 0: /* portfolio_delete_portfolio_V5 - num */;
            return _toStringPortfolioNumber_V5(
                &m->basic.portfolio_delete_portfolio_V5.num,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10754: /* module 42 call 2 */
        switch (itemIdx) {
        case 0: /* portfolio_move_portfolio_funds_V5 - from */;
            return _toStringPortfolioId_V5(
                &m->basic.portfolio_move_portfolio_funds_V5.from,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* portfolio_move_portfolio_funds_V5 - to */;
            return _toStringPortfolioId_V5(
                &m->basic.portfolio_move_portfolio_funds_V5.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* portfolio_move_portfolio_funds_V5 - items */;
            return _toStringVecMovePortfolioItem_V5(
                &m->basic.portfolio_move_portfolio_funds_V5.items,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10755: /* module 42 call 3 */
        switch (itemIdx) {
        case 0: /* portfolio_rename_portfolio_V5 - num */;
            return _toStringPortfolioNumber_V5(
                &m->basic.portfolio_rename_portfolio_V5.num,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* portfolio_rename_portfolio_V5 - to_name */;
            return _toStringPortfolioName_V5(
                &m->basic.portfolio_rename_portfolio_V5.to_name,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11008: /* module 43 call 0 */
        switch (itemIdx) {
        case 0: /* confidential_add_range_proof_V5 - target_id */;
            return _toStringIdentityId_V5(
                &m->basic.confidential_add_range_proof_V5.target_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* confidential_add_range_proof_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.confidential_add_range_proof_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* confidential_add_range_proof_V5 - secret_value */;
            return _toStringu64(
                &m->basic.confidential_add_range_proof_V5.secret_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11009: /* module 43 call 1 */
        switch (itemIdx) {
        case 0: /* confidential_add_verify_range_proof_V5 - target */;
            return _toStringIdentityId_V5(
                &m->basic.confidential_add_verify_range_proof_V5.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* confidential_add_verify_range_proof_V5 - prover */;
            return _toStringIdentityId_V5(
                &m->basic.confidential_add_verify_range_proof_V5.prover,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* confidential_add_verify_range_proof_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.confidential_add_verify_range_proof_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11520: /* module 45 call 0 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_V5 - when */;
            return _toStringBlockNumber(
                &m->nested.scheduler_schedule_V5.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_V5 - maybe_periodic */;
            return _toStringOptionPeriod_V5(
                &m->nested.scheduler_schedule_V5.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_V5 - priority */;
            return _toStringPriority_V5(
                &m->nested.scheduler_schedule_V5.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_V5 - call */;
            return _toStringCall(
                &m->nested.scheduler_schedule_V5.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11521: /* module 45 call 1 */
        switch (itemIdx) {
        case 0: /* scheduler_cancel_V5 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_cancel_V5.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_cancel_V5 - index */;
            return _toStringu32(
                &m->basic.scheduler_cancel_V5.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11522: /* module 45 call 2 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_V5 - id */;
            return _toStringBytes(
                &m->nested.scheduler_schedule_named_V5.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_V5 - when */;
            return _toStringBlockNumber(
                &m->nested.scheduler_schedule_named_V5.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_V5 - maybe_periodic */;
            return _toStringOptionPeriod_V5(
                &m->nested.scheduler_schedule_named_V5.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_V5 - priority */;
            return _toStringPriority_V5(
                &m->nested.scheduler_schedule_named_V5.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_V5 - call */;
            return _toStringCall(
                &m->nested.scheduler_schedule_named_V5.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11523: /* module 45 call 3 */
        switch (itemIdx) {
        case 0: /* scheduler_cancel_named_V5 - id */;
            return _toStringBytes(
                &m->basic.scheduler_cancel_named_V5.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11524: /* module 45 call 4 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_after_V5 - after */;
            return _toStringBlockNumber(
                &m->nested.scheduler_schedule_after_V5.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_after_V5 - maybe_periodic */;
            return _toStringOptionPeriod_V5(
                &m->nested.scheduler_schedule_after_V5.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_after_V5 - priority */;
            return _toStringPriority_V5(
                &m->nested.scheduler_schedule_after_V5.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_after_V5 - call */;
            return _toStringCall(
                &m->nested.scheduler_schedule_after_V5.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11525: /* module 45 call 5 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_after_V5 - id */;
            return _toStringBytes(
                &m->nested.scheduler_schedule_named_after_V5.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_after_V5 - after */;
            return _toStringBlockNumber(
                &m->nested.scheduler_schedule_named_after_V5.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_after_V5 - maybe_periodic */;
            return _toStringOptionPeriod_V5(
                &m->nested.scheduler_schedule_named_after_V5.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_after_V5 - priority */;
            return _toStringPriority_V5(
                &m->nested.scheduler_schedule_named_after_V5.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_after_V5 - call */;
            return _toStringCall(
                &m->nested.scheduler_schedule_named_after_V5.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11776: /* module 46 call 0 */
        switch (itemIdx) {
        case 0: /* corporateaction_set_max_details_length_V5 - length */;
            return _toStringu32(
                &m->basic.corporateaction_set_max_details_length_V5.length,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11777: /* module 46 call 1 */
        switch (itemIdx) {
        case 0: /* corporateaction_reset_caa_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.corporateaction_reset_caa_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11778: /* module 46 call 2 */
        switch (itemIdx) {
        case 0: /* corporateaction_set_default_targets_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.corporateaction_set_default_targets_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_set_default_targets_V5 - targets */;
            return _toStringTargetIdentities_V5(
                &m->basic.corporateaction_set_default_targets_V5.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11779: /* module 46 call 3 */
        switch (itemIdx) {
        case 0: /* corporateaction_set_default_withholding_tax_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.corporateaction_set_default_withholding_tax_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_set_default_withholding_tax_V5 - tax */;
            return _toStringTax_V5(
                &m->basic.corporateaction_set_default_withholding_tax_V5.tax,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11780: /* module 46 call 4 */
        switch (itemIdx) {
        case 0: /* corporateaction_set_did_withholding_tax_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.corporateaction_set_did_withholding_tax_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_set_did_withholding_tax_V5 - taxed_did */;
            return _toStringIdentityId_V5(
                &m->basic.corporateaction_set_did_withholding_tax_V5.taxed_did,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* corporateaction_set_did_withholding_tax_V5 - tax */;
            return _toStringOptionTax_V5(
                &m->basic.corporateaction_set_did_withholding_tax_V5.tax,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11781: /* module 46 call 5 */
        switch (itemIdx) {
        case 0: /* corporateaction_initiate_corporate_action_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.corporateaction_initiate_corporate_action_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_initiate_corporate_action_V5 - kind */;
            return _toStringCAKind_V5(
                &m->basic.corporateaction_initiate_corporate_action_V5.kind,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* corporateaction_initiate_corporate_action_V5 - decl_date */;
            return _toStringMoment_V5(
                &m->basic.corporateaction_initiate_corporate_action_V5.decl_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* corporateaction_initiate_corporate_action_V5 - record_date */;
            return _toStringOptionRecordDateSpec_V5(
                &m->basic.corporateaction_initiate_corporate_action_V5.record_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* corporateaction_initiate_corporate_action_V5 - details */;
            return _toStringCADetails_V5(
                &m->basic.corporateaction_initiate_corporate_action_V5.details,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* corporateaction_initiate_corporate_action_V5 - targets */;
            return _toStringOptionTargetIdentities_V5(
                &m->basic.corporateaction_initiate_corporate_action_V5.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* corporateaction_initiate_corporate_action_V5 - default_withholding_tax */;
            return _toStringOptionTax_V5(
                &m->basic.corporateaction_initiate_corporate_action_V5.default_withholding_tax,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 7: /* corporateaction_initiate_corporate_action_V5 - withholding_tax */;
            return _toStringOptionVecTupleIdentityIdTax_V5(
                &m->basic.corporateaction_initiate_corporate_action_V5.withholding_tax,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11782: /* module 46 call 6 */
        switch (itemIdx) {
        case 0: /* corporateaction_link_ca_doc_V5 - id */;
            return _toStringCAId_V5(
                &m->basic.corporateaction_link_ca_doc_V5.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_link_ca_doc_V5 - docs */;
            return _toStringVecDocumentId_V5(
                &m->basic.corporateaction_link_ca_doc_V5.docs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11783: /* module 46 call 7 */
        switch (itemIdx) {
        case 0: /* corporateaction_remove_ca_V5 - ca_id */;
            return _toStringCAId_V5(
                &m->basic.corporateaction_remove_ca_V5.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11784: /* module 46 call 8 */
        switch (itemIdx) {
        case 0: /* corporateaction_change_record_date_V5 - ca_id */;
            return _toStringCAId_V5(
                &m->basic.corporateaction_change_record_date_V5.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_change_record_date_V5 - record_date */;
            return _toStringOptionRecordDateSpec_V5(
                &m->basic.corporateaction_change_record_date_V5.record_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12032: /* module 47 call 0 */
        switch (itemIdx) {
        case 0: /* corporateballot_attach_ballot_V5 - ca_id */;
            return _toStringCAId_V5(
                &m->basic.corporateballot_attach_ballot_V5.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateballot_attach_ballot_V5 - range */;
            return _toStringBallotTimeRange_V5(
                &m->basic.corporateballot_attach_ballot_V5.range,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* corporateballot_attach_ballot_V5 - meta */;
            return _toStringBallotMeta_V5(
                &m->basic.corporateballot_attach_ballot_V5.meta,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* corporateballot_attach_ballot_V5 - rcv */;
            return _toStringbool(
                &m->basic.corporateballot_attach_ballot_V5.rcv,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12033: /* module 47 call 1 */
        switch (itemIdx) {
        case 0: /* corporateballot_vote_V5 - ca_id */;
            return _toStringCAId_V5(
                &m->basic.corporateballot_vote_V5.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateballot_vote_V5 - votes */;
            return _toStringVecBallotVote_V5(
                &m->basic.corporateballot_vote_V5.votes,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12034: /* module 47 call 2 */
        switch (itemIdx) {
        case 0: /* corporateballot_change_end_V5 - ca_id */;
            return _toStringCAId_V5(
                &m->basic.corporateballot_change_end_V5.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateballot_change_end_V5 - end */;
            return _toStringMoment_V5(
                &m->basic.corporateballot_change_end_V5.end,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12035: /* module 47 call 3 */
        switch (itemIdx) {
        case 0: /* corporateballot_change_meta_V5 - ca_id */;
            return _toStringCAId_V5(
                &m->basic.corporateballot_change_meta_V5.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateballot_change_meta_V5 - meta */;
            return _toStringBallotMeta_V5(
                &m->basic.corporateballot_change_meta_V5.meta,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12036: /* module 47 call 4 */
        switch (itemIdx) {
        case 0: /* corporateballot_change_rcv_V5 - ca_id */;
            return _toStringCAId_V5(
                &m->basic.corporateballot_change_rcv_V5.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateballot_change_rcv_V5 - rcv */;
            return _toStringbool(
                &m->basic.corporateballot_change_rcv_V5.rcv,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12037: /* module 47 call 5 */
        switch (itemIdx) {
        case 0: /* corporateballot_remove_ballot_V5 - ca_id */;
            return _toStringCAId_V5(
                &m->basic.corporateballot_remove_ballot_V5.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12288: /* module 48 call 0 */
        switch (itemIdx) {
        case 0: /* capitaldistribution_distribute_V5 - ca_id */;
            return _toStringCAId_V5(
                &m->basic.capitaldistribution_distribute_V5.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* capitaldistribution_distribute_V5 - portfolio */;
            return _toStringOptionPortfolioNumber_V5(
                &m->basic.capitaldistribution_distribute_V5.portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* capitaldistribution_distribute_V5 - currency */;
            return _toStringTicker_V5(
                &m->basic.capitaldistribution_distribute_V5.currency,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* capitaldistribution_distribute_V5 - amount */;
            return _toStringBalance(
                &m->basic.capitaldistribution_distribute_V5.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* capitaldistribution_distribute_V5 - payment_at */;
            return _toStringMoment_V5(
                &m->basic.capitaldistribution_distribute_V5.payment_at,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* capitaldistribution_distribute_V5 - expires_at */;
            return _toStringOptionMoment_V5(
                &m->basic.capitaldistribution_distribute_V5.expires_at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12289: /* module 48 call 1 */
        switch (itemIdx) {
        case 0: /* capitaldistribution_claim_V5 - ca_id */;
            return _toStringCAId_V5(
                &m->basic.capitaldistribution_claim_V5.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12290: /* module 48 call 2 */
        switch (itemIdx) {
        case 0: /* capitaldistribution_push_benefit_V5 - ca_id */;
            return _toStringCAId_V5(
                &m->basic.capitaldistribution_push_benefit_V5.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* capitaldistribution_push_benefit_V5 - holder */;
            return _toStringIdentityId_V5(
                &m->basic.capitaldistribution_push_benefit_V5.holder,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12291: /* module 48 call 3 */
        switch (itemIdx) {
        case 0: /* capitaldistribution_reclaim_V5 - ca_id */;
            return _toStringCAId_V5(
                &m->basic.capitaldistribution_reclaim_V5.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12292: /* module 48 call 4 */
        switch (itemIdx) {
        case 0: /* capitaldistribution_remove_distribution_V5 - ca_id */;
            return _toStringCAId_V5(
                &m->basic.capitaldistribution_remove_distribution_V5.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12544: /* module 49 call 0 */
        switch (itemIdx) {
        case 0: /* checkpoint_create_checkpoint_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.checkpoint_create_checkpoint_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12545: /* module 49 call 1 */
        switch (itemIdx) {
        case 0: /* checkpoint_set_schedules_max_complexity_V5 - max_complexity */;
            return _toStringu64(
                &m->basic.checkpoint_set_schedules_max_complexity_V5.max_complexity,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12546: /* module 49 call 2 */
        switch (itemIdx) {
        case 0: /* checkpoint_create_schedule_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.checkpoint_create_schedule_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* checkpoint_create_schedule_V5 - schedule */;
            return _toStringScheduleSpec_V5(
                &m->basic.checkpoint_create_schedule_V5.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12547: /* module 49 call 3 */
        switch (itemIdx) {
        case 0: /* checkpoint_remove_schedule_V5 - ticker */;
            return _toStringTicker_V5(
                &m->basic.checkpoint_remove_schedule_V5.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* checkpoint_remove_schedule_V5 - id */;
            return _toStringScheduleId_V5(
                &m->basic.checkpoint_remove_schedule_V5.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V5(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2051: // Staking:Withdraw Unbonded
        switch (itemIdx) {
        case 0: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 2068: // Staking:Force unstake
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 2074: // Staking:Reap stash
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }

    default:
        return false;
    }
}