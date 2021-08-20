using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class ItemRotateDoubleOne : MonoBehaviour, IUpdate
{
    public ManagerInput ManagerInput;
    public ManagerLevel ManagerLevel;
    [Space]

    public ItemRotateDoubleItem Parrent;
    [Space]

    public float SpeedRotation = 0.2f;
    public float SpeedAutoTurn = 2.0f;
    [Space]

    private float _dotRotation;
    private Quaternion _saccessRotation;

    private bool _doubleType;
    private bool _mausePressed;
    private Vector3 _mousePosition;

    private Vector3 _itemRotation;

	private void Start()
	{
        _saccessRotation = transform.rotation;
        Vector3 _rotationEuler = transform.rotation.eulerAngles;

        transform.rotation = Quaternion.Euler(_rotationEuler.x + Random.Range(60.0f, 300.0f),
                                                _rotationEuler.y + Random.Range(60.0f, 300.0f),
                                                _rotationEuler.z);
    }

    public void ObjectUpdate()
    {
        SwitchDoubleType();
        AutoTurn();
        ProcessRotation();
    }

    private void SwitchDoubleType()
    {
        _doubleType = ManagerInput.IsLeftControl();
        
        if (_doubleType == true)
        {
            gameObject.GetComponent<SphereCollider>().enabled = false;
        }
        else
        {
            gameObject.GetComponent<SphereCollider>().enabled = true;
        }
    }

    private void AutoTurn()
	{
        if (Parrent.IsAutoTurn() == true)
        {
            transform.rotation = Quaternion.Slerp(transform.rotation, _saccessRotation, SpeedAutoTurn * Time.deltaTime);
            _dotRotation = Mathf.Abs(Quaternion.Dot(transform.rotation, _saccessRotation));
        }
    }

    private void ProcessRotation()
	{
        if (Parrent.IsAutoTurn() == false && _mausePressed == true)
        {
            float angleX = (_mousePosition.y - Input.mousePosition.y) * SpeedRotation;
            float angleY = (_mousePosition.x - Input.mousePosition.x) * SpeedRotation;

            gameObject.transform.rotation = Quaternion.Euler(_itemRotation.x + angleX, _itemRotation.y + angleY, _itemRotation.z);
		}

        CheckSaccess();
	}

    public float GetDotRotation()
	{
        return _dotRotation;
	}

    private void CheckSaccess()
	{
        _dotRotation = Mathf.Abs(Quaternion.Dot(transform.rotation, _saccessRotation));
    }

	private void OnMouseDown()
	{
        if (_doubleType == false)
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
