def test_cavi_imports():
    from cavi import status, data


def test__cavi_built():
    from cavi import _cavi


def test__cavi_alliases():
    import cavi

    assert cavi.status == cavi._cavi.status
    assert cavi.data == cavi._cavi.data
