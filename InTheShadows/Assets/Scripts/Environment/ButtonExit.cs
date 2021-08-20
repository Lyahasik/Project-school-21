using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ButtonExit : MonoBehaviour
{
	public ManagerLevel ManagerLevel;

	private void OnMouseDown()
	{
		ManagerLevel.ClosingScene();
	}
}
