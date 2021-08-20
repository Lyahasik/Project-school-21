using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ManagerGlobal : MonoBehaviour
{
	public List<GameObject> Objects;

	private List<IUpdate> _componentsIUpdate;

	private void Start()
	{
		_componentsIUpdate = new List<IUpdate>();

		foreach (GameObject obj in Objects)
		{
			IUpdate[] componentsIUpdate = obj.GetComponents<IUpdate>();
			 
			foreach (IUpdate component in componentsIUpdate)
			{
				_componentsIUpdate.Add(component);
			}
		}
	}

	void Update()
    {
        foreach (IUpdate component in _componentsIUpdate)
		{
			component.ObjectUpdate();
		}
    }
}
