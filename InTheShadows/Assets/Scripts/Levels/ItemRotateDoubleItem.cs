using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class ItemRotateDoubleItem : MonoBehaviour, IUpdate
{
    public ManagerInput ManagerInput;
    public ManagerLevel ManagerLevel;
    [Space]

    public ItemRotateDoubleOne FirstChildren;
    public ItemRotateDoubleOne SecondChildren;
    [Space]

    [Range(2.0f, 3.0f)]
    public float SuccessValue = 2.85f;
    public float SpeedRotation = 0.2f;
    public float SpeedAutoTurn = 2.0f;
    public bool AxisX;
    [Space]

    public Light SpotLight;

    private float _dotRotation;
    private float _dotCommon;
    private Quaternion _saccessRotation;

    private bool _doubleType;
    private bool _mausePressed;
    private Vector3 _mousePosition;

    private Vector3 _itemRotation;
    private bool _autoTurn;

	private void Start()
	{
        _saccessRotation = transform.rotation;

        Vector3 _rotationEuler = transform.rotation.eulerAngles;

        transform.rotation = Quaternion.Euler(_rotationEuler.x + (AxisX == true ? Random.Range(60.0f, 300.0f) : 0),
                                                _rotationEuler.y + Random.Range(60.0f, 300.0f),
                                                _rotationEuler.z);
    }

    public void ObjectUpdate()
    {
        SwitchDoubleType();
        ChangeShadowStrength();
        AutoTurn();
        ProcessRotation();
    }

    private void SwitchDoubleType()
    {
        _doubleType = ManagerInput.IsLeftControl();

        if (_doubleType == true)
		{
            gameObject.GetComponent<SphereCollider>().enabled = true;
		}
        else
		{
            gameObject.GetComponent<SphereCollider>().enabled = false;
        }
    }

    private void ChangeShadowStrength()
	{
        if (_dotCommon >= 0.9f && _dotCommon <= 3.0f)
        {
            SpotLight.shadowStrength = _dotCommon / 3.0f;
        }
    }

    public bool IsAutoTurn()
	{
        return _autoTurn;
	}

    private void AutoTurn()
	{
        if (_autoTurn == true)
        {
            transform.rotation = Quaternion.Slerp(transform.rotation, _saccessRotation, SpeedAutoTurn * Time.deltaTime);
            _dotRotation = Mathf.Abs(Quaternion.Dot(transform.rotation, _saccessRotation));

            if (_dotRotation == 1.0f)
            {
                ManagerLevel.SetAutoTurn(false);
                ManagerLevel.LevelSuccess();
            }
        }
    }

    private void ProcessRotation()
	{
        if (_autoTurn == false && _mausePressed == true)
        {
            if (AxisX == true)
            {
                float angleX = (_mousePosition.y - Input.mousePosition.y) * SpeedRotation;
                float angleY = (_mousePosition.x - Input.mousePosition.x) * SpeedRotation;

                gameObject.transform.rotation = Quaternion.Euler(_itemRotation.x + angleX, _itemRotation.y + angleY, _itemRotation.z);
            }
            else
            {
                float angleY = (_mousePosition.x - Input.mousePosition.x) * SpeedRotation;

                gameObject.transform.rotation = Quaternion.Euler(_itemRotation.x, _itemRotation.y + angleY, _itemRotation.z);
            }
		}

        CheckSaccess();
	}

    private void CheckSaccess()
	{
        _dotRotation = Mathf.Abs(Quaternion.Dot(transform.rotation, _saccessRotation));
        float _dotRotationFirstChildren = FirstChildren.GetDotRotation();
        float _dotRotationSecondChildren = SecondChildren.GetDotRotation();

        _dotCommon = _dotRotation + _dotRotationFirstChildren + _dotRotationSecondChildren;

        if (_dotCommon > SuccessValue)
        {
            _autoTurn = true;
            ManagerLevel.SetAutoTurn(true);
        }
    }

	private void OnMouseDown()
	{
		if (_doubleType == true)
		{
			_mausePressed = true;
			_mousePosition = Input.mousePosition;
			_itemRotation = gameObject.transform.rotation.eulerAngles;
		}
	}

	private void OnMouseUp()
	{
		_mausePressed = false;
	}
}
