using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class ItemRotateY : MonoBehaviour, IUpdate
{
    public ManagerLevel ManagerLevel;
    [Space]

    public float SpeedRotation = 0.2f;
    public float SpeedAutoTurn = 2.0f;
    [Space]

    public Light SpotLight;

    private float _dotRotation;
    private Quaternion _saccessRotation;

    private bool _mausePressed;
    private Vector3 _mousePosition;

    private Vector3 _itemRotation;
    private bool _autoTurn;

	private void Start()
	{
        _saccessRotation = transform.rotation;

        Vector3 _rotationEuler = transform.rotation.eulerAngles;

        transform.rotation = Quaternion.Euler(_rotationEuler.x,
                                                _rotationEuler.y + Random.Range(60.0f, 300.0f),
                                                _rotationEuler.z);
    }

    public void ObjectUpdate()
    {
        ChangeShadowStrength();
        AutoTurn();
        ProcessRotation();
    }

    private void ChangeShadowStrength()
	{
        if (_dotRotation >= 0.3f && _dotRotation <= 1.0f)
        {
            SpotLight.shadowStrength = _dotRotation;
        }
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
            float angleY = (_mousePosition.x - Input.mousePosition.x) * SpeedRotation;

            gameObject.transform.rotation = Quaternion.Euler(_itemRotation.x, _itemRotation.y + angleY, _itemRotation.z);
		}

        CheckSaccess();
	}

    private void CheckSaccess()
	{
        _dotRotation = Mathf.Abs(Quaternion.Dot(transform.rotation, _saccessRotation));

        if (_dotRotation > 0.98f)
        {
            _autoTurn = true;
            ManagerLevel.SetAutoTurn(true);
        }
    }

	private void OnMouseDown()
	{
        _mausePressed = true;
        _mousePosition = Input.mousePosition;
        _itemRotation = gameObject.transform.rotation.eulerAngles;
    }

	private void OnMouseUp()
	{
        _mausePressed = false;
    }
}
