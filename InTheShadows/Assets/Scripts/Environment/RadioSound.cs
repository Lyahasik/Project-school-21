using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RadioSound : MonoBehaviour
{
	public ManagerSettings ManagerSettings;

	private void OnMouseDown()
	{
		ManagerSettings.SwitchPause();
	}
}
