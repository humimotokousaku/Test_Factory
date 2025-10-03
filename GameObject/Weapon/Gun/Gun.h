#pragma once
#include "../IWeapon.h"
#include "Components/Magazine.h"
#include <memory>

/// <summary>
/// �e�̊��N���X
/// </summary>
class Gun : public IWeapon {
public:
	// �R���X�g���N�^
	Gun() = default;
	// �f�X�g���N�^
	~Gun() override = default;

	/// <summary>
	/// ������
	/// </summary>
	virtual void Init() override = 0;
	/// <summary>
	/// �X�V
	/// </summary>
	virtual void Update() override = 0;
	/// <summary>
	/// ��������
	/// </summary>
	virtual void DebugGui() = 0;

	/// <summary>
	/// �ˌ�
	/// </summary>
	virtual void Shoot() = 0;
	/// <summary>
	/// �����[�h
	/// </summary>
	virtual void Reload() = 0;
	/// <summary>
	/// �_��(ADS)
	/// </summary>
	virtual void Aim() = 0;

protected:// ��������
	// �ˌ��Ԋu[�b]
	float shotIntervalTime_;

protected:
	// �e�q
	std::unique_ptr<Magazine> magazine_;
};