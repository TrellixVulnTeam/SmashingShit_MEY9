﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SlingshotPellet : MonoBehaviour {

    private float _velocity = 1.0f;

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
        transform.Translate(new Vector3(0.0f, 0.0f, _velocity) * Time.deltaTime);
	}
}
